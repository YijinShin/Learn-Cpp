/*

void func(int *iArray);		
void func(int iArray[]);
// �̰� �Ѵ� �迭�� ù��° '�ּ�'�� �Լ��� �Ű������� �����ϴ� ����!! 
--------------------------------------------------------------------
�Լ� ������


---------------------------------------------------------------------

����1
2���� �迭�� �̿��ؼ� �ð� �������� 90�� 4ȸ�� ��Ű�� 

1	2	3
4	5	6
7	8	9

7	4	1
8	5	2
9	6	3

9	8	7	
6	5	4
3	2	1

3	6	9
2	5	8
1	4	7

1	2	3
4	5	6	
7	8	9

[0,0] -> [0,2] [j, 3-0-1]
[0,1] -> [1,2] [j, 3-0-1]
[0,2] -> [2,2]

[2,0] -> [0,0]
[1,0] -> [0,1]
[0,0] -> [0,2]




����2)
�߱����� �����
 1~9������ �����߿� �������� 3���� �����Ѵ�.(�̰� ������Ҵ�) (������ ���� �ʴ´�)
 ���� 3���� �Է¹ް�, ���� ������ ��ġ�� ��� = ��Ʈ����ũ
 ���� ��ġ�ϰ�, ������ �ٸ��� = ��
 ��ȸ���� ��Ʈ����ũ�� ���� ����Ͽ� ���
 3��Ʈ����ũ�� ��� �¸�, 9ȸ������ �����Ͽ� 3��Ʈ����ũ�� �� ����� �й�

 ��) 8	 2	1
 1ȸ�� �Է�) 1	2	3 => 1��Ʈ����ũ(2) 1��(1)
 2ȸ�� �Է�) 2	3	4 => 1��(2)
 3ȸ�� �Է�) 8	1	2 => 1��Ʈ����ũ(8) 2��(1,2)


 ����3)

*/