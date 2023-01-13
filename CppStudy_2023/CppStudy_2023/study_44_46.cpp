/* [ C++ study with TCP school 38part]
topic: Ŭ���� / OOP / �������� ������


* Ŭ����
	- ��ü ���� ���α׷����� �� �� �ְ� ���� 
	- ����ü�� Ȯ����
	- ����ü�� ������
		- �ɹ��� �Լ� ���԰���
		- ���� ���� 

* ��ü ���� ���α׷��� (OOP : Object-Oriented Programming)
	- ��� �����͸� '��ü'�� �����
	- ��ü�� ���¿� �ൿ�� ��üȭ�ϴ� ������ ���α׷����� �� 
	- '��ü'�� ����� Ʋ = class

	- OOP�� Ư¡ 5�� 		 

			1. �߻�ȭ(abstraction)	 -> Ŭ����

			2. ĸ��ȭ(encapsulation)

			3. ���� ����(data hiding)

			4. ��Ӽ�(inheritance)

			5. ������(polymorphism)


* �ν��Ͻ� (instance)
	- Ŭ���� Ÿ�� ��ü�� �ν��Ͻ���� �Ѵ�. (�޸𸮿� ���Ե� ��ü)
	- �翬�� �ϳ��� Ŭ�������� ���� ���� �ν��Ͻ� ���� ����
	- �ɹ� ���� -> �� �ν��Ͻ��� ������(�������� �޸� ����)���� ����
	- �ɹ� �Լ� -> ��� �ν��Ͻ��� ������

* �ɹ� �Լ�
	- Ŭ���� ������� ��, �� ��ο��� ���� ����. 
	  ���� Ŭ���� �ۿ��� �Լ��� ������ ��� �Լ� ������ Ŭ���� ����ο� �־����.

------------------------------------------------------------------------------------------------------------------------------------------
* �������� ( access control )
	- ����ü�� ��� �ɹ��� �ܺο��� ������ ������. �׷��� Ŭ������ ���� ����(data hiding)�� �����ϴ�. 
	- Ŭ������ �����ϸ�, �� �ȿ� �ɹ����� ���� ��� ����������Ѵ�.
	
	- [ private ] 
		
		- ���� Ŭ������, private�̳� public �ɹ��Լ����� ���ٰ��� ( �ܺο� ���еǴ� ����)
		- �ٵ� �⺻������ ��� Ŭ������ �ɹ��� ����� private���� ������. �׷��� private �����ڸ� ���� �ʿ�� ����.

	- [ public ]
		
		- �ش� Ŭ���� ��ü�� ����ϴ� ���α׷� ��𼭳� �������� ����
		  ( ���� ��Ű��, �ٸ���Ű�� ��ο��� ���ٰ���)
		- ���� �ַ� private �ɹ��� ���α׷� ������ �������̽� ������ ��
		- public �Լ��� public, private�ɹ� ��ο� ���� ����

	- [ protected ]

		- �Ļ�Ŭ����(derived class) �� ���õ� �������� ������		(�ڼ��ѰŴ� study 57����)
		- �Ļ� Ŭ������ ���ؼ��� -> public�ɹ��� ��޵�
		  �� �ܿ� (�ܺο���)���ؼ��� -> private�ɹ��� ��޵�
			
		  ��, ���� ��Ű�� �ȿ����� ���� ����, �ٸ� ��Ű�������� ���� �Ұ��� 
 
------------------------------------------------------------------------------------------------------------------------------------------

* 

*/

#include <iostream>
#include <string>

using namespace std;


// Ŭ���� ���� 
class Pokemon
{
	// �������� ������:
	private:
		//�ɹ� ����1
		float weight;
		//�ɹ� ����2
		float height;
		//�ɹ� �Լ�1 _ Ŭ���� ����ο��� �Լ��� ������ ��� 
		void DisplayInfo_private() { cout << "[private] �̸�: " << name << ", Ű: " << height << ", ������: " << weight << endl; }
		//�ɹ� �Լ�2 _ Ŭ���� ����ο����� �Լ� ������ ����, ���Ǵ� Ŭ���� �ۿ� ����
		void DisplayInfo_private_2();
	
	// �������� ������:
	public:
		//�ɹ� ����1
		string type = "000";
		//�ɹ� ����3
		string name = "000";
		//�ɹ� �Լ�1
		void DisplayInfo_public() { cout << "[public] �̸�: " << name << ", Ű: " << height << ", ������: " << weight << endl;}
		void CallPrivateFunction() { DisplayInfo_private(); }
		
		//�ɹ� �Լ�(get�Լ�)
		void getWeight(float w) { weight = w; }
		void getHeight(float h) { height = h; }


};

// Ŭ���� �ۿ��� �ɹ� �Լ��� ������ ��� 
void Pokemon::DisplayInfo_private_2() { cout << "[private + outside] �̸�: " << name << ", Ű: " << height << ", ������: " << weight << endl; }


int main() {

	// �ν��Ͻ� ����
	Pokemon pikachu;


	// [ private �ɹ��� ���� ]
	//pikachu.weight = 10.f		// weight�� private �ɹ��� �̷��Դ� ������ �ȵ� 
	pikachu.getWeight(10.f);	// private �ɹ������� ���� �������� �̷��� public �ɹ��� get�Լ��� �����ؼ� �ؾ���. 
	pikachu.getHeight(20.f);
	//pikachu.DisplayInfo_private(); // private �Լ��� ���������� �ٷ� ������ �ȵ�
	
	// [ public �ɹ��� ����]
	getline(cin, pikachu.name);
	pikachu.DisplayInfo_public();



}