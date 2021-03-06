#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;
#define Size_Max 1024

	class stack{
		char A[Size_Max];
		char top;
	public:
		stack(){
			top = -1;
		}
	
	void push(char n){
		if (top == Size_Max-1){
			cout<<" Array Berlebih "<<endl;
			return;
		}
		A[++top]=n;
	}
	
	void pop(){
		if (top == -1){
			cout<<" Element tidak bisa diPOP "<<endl;
			return;
		}
			else top--;
	}

	int Top(){
		return A[top];
	}

	bool IsEmpty(){				// ketika kosong
		if (top <0 ){
			return 1;
		}
			else {
				return 0;
			}
	}
};


	int prakondisi (char k){			// pertimbangan susunan operasi yang harus dahulu dilakukan
    	if (k == '*' || k == '/')
    	return 2;
    	else if (k == '+' || k == '-')
    	return 1;
    	else
    	return -1;
	}

int main(){
	stack s;
	int banyak, nilai;
	string o,pf;
	getline(cin, o);
	banyak = o.length();

	for(int i=0; i<=banyak; i++){
		if (o[i] >= '0' && o[i] <= '9'){
			pf+=o[i];
		}
			else if (o[i] ==  '('){
				s.push(o[i]);
			}
				else if (o[i] == ')'){
					while (s.IsEmpty() != 1 && s.Top() != '('){
					char k = s.Top();
					s.pop();
				pf+=k;
					}
						if (s.Top() == '('){
							s.pop();
						}
				}
			if (o[i] == '+' || o[i] == '-' || o[i] == '*' || o[i] == '/'){
				if (s.IsEmpty() == 1 || s.Top() == '('){
					s.push (o[i]);
			}
		
				else{
					while (s.IsEmpty() != 1 && s.Top() != '(' && prakondisi(o[i]) <= prakondisi(s.Top())){
						char k = s.Top();
						s.pop();
					pf+=k;
			}
				s.push (o[i]);
			}	
		}
	}
	while (s.IsEmpty() != 1){
			char k = s.Top();
			s.pop();
			pf+=k;
	}
	
	cout<<" Postfix : "<<pf<<endl;
	
	for (int i=0; i<=banyak; i++){
	if (pf[i] >= '0' && pf[i] <= '9'){
			s.push(pf[i]);
	}
	if (pf[i] == '+' || pf[i] == '-' || pf[i] == '*' || pf[i] == '/'){
		int A = s.Top()-'0';
		s.pop();
		
		int B = s.Top()-'0';
		s.pop();
	
		if (pf[i] == '+'){
			nilai = B+A;
			char tmpnilai = nilai+'0';
			s.push(tmpnilai);
		}
			else if (pf[i] == '-'){
				nilai = B-A;
				char tmpnilai = nilai+'0';
				s.push(tmpnilai);
			
			}
				else if (pf[i] == '*'){
					nilai = B*A;
					char tmpnilai = nilai+'0';
					s.push(tmpnilai);
				}
					else if (pf[i] == '/'){
						nilai = B/A;
						char tmpnilai = nilai+'0';
						s.push(tmpnilai);
					}
		
	}

	}
	char NilaiAkhir = s.Top();
	int Nilai = NilaiAkhir-'0';			//pembulatan ke-bawah
	cout<<" Akhir : "<<Nilai<<endl;
	
}

