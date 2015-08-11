#include <vcl>
#include <vector>
#include <iostream>

namespace moo
{



	class Vector
	{
			int * mas;
			int mas_size;

		public:

			Vector(); //����������� �� ���������
						 /* �������� � ���� ������� ������,
						 ��� ����������� � ������� �� �������.
						 � ����� ��� ��� ��������, ���� ��������
						 ����������.			 */
			void Pushback(int);
			void IndexMutator(int);
			sizeAccessor() { return mas_size;};
			~Vector() { delete[] mas; };
			int& operator[](int ind_mas) { return mas[ind_mas]; };
	};

	Vector::Vector() : mas(0), mas_size(0) {} //����������� �� ���������
                       //������ �������������
	void Vector::IndexMutator(int ind)
	{
		mas_size = ind;
	}

	void Vector::Pushback(int elem)
	{
		int * new_mas = new int[mas_size+1]; //���������� ������ ��� �������,
											 //������ ������� �������+1
		for (int i = 0; i < mas_size; i++)   //��������� �� �������� ������� �������
			new_mas[i]=mas[i];               //���������� � ��������� ������

		delete[] mas;      //������, ���������� mas ���������
		mas = new_mas;     //mas �������� ��������� �� ����� ���������� ������,
						   //�� ������� ������ �������� new_mas
		mas[mas_size++] = elem; //������� ����������� � ������, ������ ������������� ��� ��������� ��������
		//��������� ����������� ������, ��� ������ ���������� (�������������) ������ � ������ � ��� ��� ������, �������
		//��� �������� ���������� � ������ ���� �� 0, � ������ ����� ������������� ������ ������� mas_size
	}
}


void show_vector( std::vector<int>&a)
{
		for (std::vector<int>::iterator it = a.begin() ; it!=a.end() ; ++it)
				std::cout << *it << '\n';
}

void show_my_vector(moo::Vector & b)
{
	int max_size = b.sizeAccessor();

	for (int i = 0; i < max_size; i++)
		std::cout << "moi vectorok-massivok " << b[i] << '\n' ;
}




int main()
{
	using namespace moo;

	Vector K;
	K.Pushback(666);
	K.Pushback(222);

	std::vector<int> V;

	V.push_back(123);
	V.push_back(6574);
	
	show_my_vector(K);
	show_vector(V);
	
	system("pause");
	return 0;
}
