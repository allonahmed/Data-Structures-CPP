#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class Node
	{
	private:
		T data;
		Node<T>* link;

		Node(const Node<T>& obj);
		Node& operator=(const Node<T>& rhs);
	public:
		Node() : Node(T(),NULL) {}

		Node(const T& data) : Node(data,NULL) {}

		Node(const T& data,Node<T>* link) : data(data), link(link) {}

		~Node() {}
	
		T& GetData() {return data;}

		const T& GetData() const {return data;}

		Node<T>* GetLink() {return link;}

		const Node<T>* GetLink() const {return link;}

		void SetData(const T& data) {this->data = data;}

		void SetLink(Node<T>* link) {this->link = link;}

		std::string ToString() const
		{
			std::stringstream out;
			out << data;
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Node<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};

	namespace sn
	{
		template<typename T>
		void Clear(Node<T>*& root)
		{
			Node<T> *tmp;

			while(root != NULL)
			{
				tmp = root;
				root = root->GetLink();
				delete tmp;
				tmp = NULL;
			}
		}

		template<typename T>
		Node<T>* Copy(Node<T>* root)
		{
			if(root == NULL)
			{
				return NULL;
			}
			
			Node<T> *head = new Node<T>(root->GetData());
			Node<T> *tmp2 = head;
			Node<T> *tmp1 = root->GetLink();

			while(tmp1 != NULL)
			{
				tmp2->SetLink(new Node<T>(tmp1->GetData()));
				tmp1 = tmp1->GetLink();
				tmp2 = tmp2->GetLink();
			}

			return head;
		}
	}
}
		
#endif
