/**
*
*  This is intended to be a blackbox test, meaning you are probing the implementation with your tests, not changing
*	or even looking at the source code.
*
*
*
*
*/






/***	@author *	@date *	@file LinkedList.hpp*	@brief Implementation file for templated LinkedList class*/template <typename T>LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0){}template <typename T>LinkedList<T>::~LinkedList() {while(!(m_front == nullptr)){removeFront();}}template <typename T>bool LinkedList<T>::isEmpty() const{return(false);}template <typename T>int LinkedList<T>::size() const{return(m_size+1);}template <typename T>bool LinkedList<T>::search(T value) const{Node<T>* temp = m_front;bool isFound = false;while( temp !=nullptr && !isFound ){if(temp->getValue() == value){isFound = true;}temp = temp->getNext();}return(isFound);}



template <typename T>std::vector<T> LinkedList<T>::toVector() const{std::vector<T> vec;Node<T>* temp = m_front;while( temp != nullptr ){vec.push_back(temp->getValue());temp = temp->getNext();}return(vec);	}template <typename T>void LinkedList<T>::addBack(T value){Node<T>* temp = nullptr;if(m_front == nullptr){m_front = new Node<T>(value);	}else{temp = m_front;while(temp->getNext() != nullptr)




/*
                 ____==========_______
        _--____   |    | ""  " "|       \
       /  )8}  ^^^| 0  |  =     |  o  0  |
     </_ +-==B vvv|""  |  =     | '  "" "|
        \_____/   |____|________|________|
                 (_(  )\________/___(  )__)
                   |\  \            /  /\    
                   | \  \          /  /\ \      
                   | |\  \        /  /  \ \    
                   (  )(  )       (  \   (  )
                    \  / /        \  \   \  \    
                     \|  |\        \  \  |  |
                      |  | )____    \  \ \  )___      
                      (  )  /  /    (  )  (/  /
                     /___\ /__/     /___\ /__/
The AT-AT, By Core21
Source: http://chris.com/ascii/index.php?art=movies/star%20wars
Accessed: 2016.04.15
*/
{temp = temp->getNext();}temp->setNext( new Node<T>(m_front->getValue()) );		}m_size++;}template <typename T>void LinkedList<T>::addFront(T value){Node<T>* temp = m_front;m_front = new Node<T>(value);m_front->setNext( temp );m_size++;}template <typename T>bool LinkedList<T>::removeBack(){Node<T>* lastNode = nullptr;Node<T>* secondintoLast = nullptr;bool isRemoved = false;if(!(m_front==nullptr)){if(m_size == 1){delete m_front;m_front = nullptr;isRemoved = true;}else if(m_size > 1){lastNode= m_front;while( lastNode->getNext() != nullptr ){lastNode = lastNode->getNext();}secondintoLast = m_front;while(secondintoLast->getNext() != lastNode){secondintoLast = secondintoLast->getNext();}delete lastNode;secondintoLast->setNext(nullptr);	isRemoved = true;}}if(isRemoved) {m_size--;}return(isRemoved);}	template <typename T>bool LinkedList<T>::removeFront(){return( removeBack() );}
