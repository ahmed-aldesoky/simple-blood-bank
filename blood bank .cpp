#include<iostream>
#include<string>
using namespace std;
enum bloodt{
	a = 1,
	b,
	ab,
	O
};
class bloodbank{
protected:
	string name;
	bloodt bloodtype;
	int age, mo_num, A, B, AB, O;
public:
	bloodbank(){
		name = " ";
		age = 1;
		mo_num = 000000;
		bloodtype = bloodt(1);
		A = B = AB = O = 0;
	}

	void set_public_inf(){
		string name;
		int age;
		long mo_num;

		cout << "enter   name \n";
		cin >> name;
		cout << "enter   age \n";
		cin >> age;
		cout << "enter   mobile number \n";
		cin >> mo_num;
		this->name = name;
		this->age = age;
		this->mo_num = mo_num;
	}
	void getinf(){
		cout << "name:" << this->name << "\n age: " << this->age << "\n mobile number " << this->mo_num << "\n";
	}
};
//--------------------------------------
class donor :public bloodbank{
public:
	int x;
	void setblood(){
		cout << "enter the number of your blood type  \n A = 1 \n B = 2, \n AB =3, \n O = 4 \n";
		cin >> x;
		bloodtype = bloodt(x);
	}
	void operator ++ ()
	{
		if (bloodtype == bloodt(1)){
			A = A + 1;
		}
		else if (bloodtype == bloodt(2)){
			B = B + 1;
		}
		else if (bloodtype == bloodt(3)){
			AB = AB + 1;
		}
		else if(bloodtype == bloodt(4))
		{
			O = O + 1;
		}
		else{
			cout << "enter right numer \n";
		}
	}
	void getall(){
		cout <<"the blood type is "<< bloodt(x) << "\n" <<
			"amount of A \t" << A << "\n" << "amount of B \t" << B << "\n" << "amount of AB\t" << AB << "\n" << "amount of O \t" << O << "\n";
	}
};
//--------------------------------------
class needer :public bloodbank{
public:

	int x;
	void setblood(){
		cout << "enter the number of the blood type you need \n A = 1 \n B=2, \n AB=3, \n O=4 \n";
		cin >> x;
		bloodtype = bloodt(x);
	}
	void operator -- ()
	{
		if (bloodtype == bloodt(1)){
			A = A - 1;	
			if (A < 1){
				cout << "sorry we do not have enough blood of this type \n ";
				A = 0;
			}
		}
		else if (bloodtype == bloodt(2)){
			B = B - 1;
			if (B < 1){
				cout << "sorry we do not have enough blood of this type \n ";
				B = 0;
			}
		}
		else if (bloodtype == bloodt(3)){
			AB = AB - 1;
			if (AB < 1){
				cout << "sorry we do not have enough blood of this type \n ";
				AB = 0;
			}
		}
		else if (bloodtype == bloodt(4))
		{
			O = O - 1;
			if (O < 1){
				cout << "sorry we do not have enough blood of this type \n ";
				O = 0;
			}
		}
		else{
			cout << "enter right number \n";
		}
	}
	void getall(){
		cout << "the blood type is " << bloodt(x) << "\n" <<
			"amount of A \t" << A << "\n" << "amount of B \t" << B << "\n" << "amount of AB\t" << AB << "\n" << "amount of O \t" << O << "\n";
	}



};

void main(){
	bloodbank cust1;
	donor d1;
	needer n1;
here:	cust1.set_public_inf();
	bool x;
	cout << " do you donor or needer ((1/ 0)) \n";
	cin >> x;
	if (x == true){

		d1.setblood();
		++d1;
		cust1.getinf();
		d1.getall();
	}
	else if (x==false)
	{	n1.setblood();
		--n1;
		cust1.getinf();
		n1.getall();
	}
	else{
		cout << "enter right number";
	}
	bool stop;
	cout << "ifyou want end program enter (0)  enter (1) to continue \n";
	cin >> stop;
	if (stop == true){
		goto here;
	}
	cout << "***----------------thank you for use the program---------------*** \n";
	system("pause");
}
