/*start 7:17 - end:7:36 */
#include <iostream>
using namespace std;

struct Student{
    string name;
    int kra;
    int eng;
    int math;
};

void MergeSort(Student studentList[], int start, int end);
void Merge(Student studentList[], int start, int mid, int end);
char CompareName(string l_name, string r_name);

Student sorted[100000];

int main(){
    ios_base::sync_with_stdio(false); //이거 없으면 176ms, 있으면 84ms
    int studentNum;
    cin >> studentNum;

    Student studentList[studentNum];
    for(int i=0;i<studentNum;i++){
        cin >> studentList[i].name >> studentList[i].kra >> studentList[i].eng >> studentList[i].math; 
    }

    MergeSort(studentList, 0, studentNum-1);

    for(int i=0;i<studentNum;i++){
        cout << studentList[i].name << "\n";
    }

    return 0;
}

void MergeSort(Student studentList[], int start, int end){
    if(start>= end) return ;
    
    int mid = (start+end)/2;
    MergeSort(studentList, start, mid);
    MergeSort(studentList, mid+1, end);
    Merge(studentList, start, mid, end);
}   

void Merge(Student studentList[], int start, int mid, int end){
    int l = start;
    int r = mid+1;
    int index = start;

    //순서는 국영수
    while(l<=mid && r<=end){
        // 국어 비교 
        if(studentList[l].kra < studentList[r].kra){
            sorted[index++] = studentList[r++];
        }else if(studentList[l].kra > studentList[r].kra){
            sorted[index++] = studentList[l++];
        }else{
            // 영어 비교 
            if(studentList[l].eng > studentList[r].eng){
                sorted[index++] = studentList[r++];
            }else if(studentList[l].eng < studentList[r].eng){
                sorted[index++] = studentList[l++];
            }else{
                // 수학 비교 
                if(studentList[l].math < studentList[r].math){
                    sorted[index++] = studentList[r++];
                }else if(studentList[l].math > studentList[r].math){
                    sorted[index++] = studentList[l++];
                }else{
                    // 이름 비교 
                    if(CompareName(studentList[l].name, studentList[r].name) == 'l'){
                        sorted[index++] = studentList[l++];
                    }else sorted[index++] = studentList[r++];
                }
                
            }
        }
        
    }

    if(l>mid) for(int i=r;i<=end;i++) sorted[index++] = studentList[i];
    else for(int i=l;i<=mid;i++) sorted[index++] = studentList[i];

    for(int i=start;i<=end;i++) studentList[i] = sorted[i];
}

char CompareName(string l_name, string r_name){
    int i=0;
    while(1){
        if(l_name[i] < r_name[i]) return 'l';
        else if(l_name[i] > r_name[i]) return 'r';
        else i++;
    }
}