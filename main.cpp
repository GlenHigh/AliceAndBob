#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

static string tobit(string myString){
	string bit;
	for (size_t i = 0; i < myString.size(); ++i)
  {
      bit= bit +  bitset<8>(myString.c_str()[i]).to_string();
  }
	return bit;
}
static string hextobit(unsigned long H){//16bits hex to bin with zero padding
	return bitset<32>(H).to_string();
}

static string bintohex(const string &s){
    string out;
    for(uint i = 0; i < s.size(); i += 4){
        int8_t n = 0;
        for(uint j = i; j < i + 4; ++j){
            n <<= 1;
            if(s[j] == '1')
                n |= 1;
        }

        if(n<=9)
            out.push_back('0' + n);
        else
            out.push_back('A' + n - 10);
    }

    return out;
}

static string bxor(string str1, string str2){
	string myXor="";
	string lng = str1;
	string shrt= str2;
	
	if(str1.length()!=str2.length()){
		if(str1.length()>str2.length()){
			lng = str1;
			shrt = str2;
		}else{
			lng = str2;
			shrt = str1;
		}
		while(shrt.length()<lng.length()){
			shrt="0"+shrt;
		}
	}
	int n = shrt.length();
	
	for(int i=0; i<lng.length();i++){
		if(lng[n-1-i]!=shrt[n-1-i]){
			myXor = "1"+myXor;
		}else{
			myXor = "0"+myXor;
		}
	}
	return myXor;
}

static string shave(string str){
	string temp=str;
	while(temp[0]=='0' && temp.length()>1){
		temp=temp.substr(1,temp.length()-1);
	}
	return temp;
}

static string grow(string str, int n){
	if(str.length()>n){
		cout<<str<<" is longer than "<<n<<endl;
		return "";
	}
	string temp=str;
	while(temp.length()<n){
			temp="0"+temp;
		}
	return temp;
}

static string complement(string str){
	string temp="";
	for(int i =0;i<str.length();i++){
		if(str[i]=='1'){
			temp=temp+'0';
		}else{
			temp=temp+'1';
		}
	}
	return temp;
}


static string bor(string str1, string str2){
	string myret="";
	string lng = str1;
	string shrt= str2;
	
	if(str1.length()!=str2.length()){
		if(str1.length()>str2.length()){
			lng = str1;
			shrt = str2;
		}else{
			lng = str2;
			shrt = str1;
		}
		while(shrt.length()<lng.length()){
			shrt="0"+shrt;
		}
	}
	int n = shrt.length();
	
	for(int i=0; i<lng.length();i++){
		if(lng[n-1-i]=='0' and shrt[n-1-i]=='0'){
			myret = "0"+myret;
		}else{
			myret = "1"+myret;
		}
	}
	return myret;
}

static string band(string str1, string str2){
	string myret="";
	string lng = str1;
	string shrt= str2;
	
	if(str1.length()!=str2.length()){
		if(str1.length()>str2.length()){
			lng = str1;
			shrt = str2;
		}else{
			lng = str2;
			shrt = str1;
		}
		while(shrt.length()<lng.length()){
			shrt="0"+shrt;
		}
	}
	int n = shrt.length();
	
	for(int i=0; i<lng.length();i++){
		if(lng[n-1-i]=='1' and shrt[n-1-i]=='1'){
			myret = "1"+myret;
		}else{
			myret = "0"+myret;
		}
	}
	return myret;
}

static string bplus(string str1, string str2){
	string myret="";
	string lng = str1;
	string shrt= str2;
	char rem ='0';
	if(str1.length()!=str2.length()){
		if(str1.length()>str2.length()){
			lng = str1;
			shrt = str2;
		}else{
			lng = str2;
			shrt = str1;
		}
		while(shrt.length()<lng.length()){
			shrt="0"+shrt;
		}
	}
	int n = shrt.length();
	
	for(int i=0; i<lng.length();i++){
		if(lng[n-1-i]=='0' and shrt[n-1-i]=='0'){
			if(rem=='0'){
				myret="0"+myret;
			}else{
				myret="1"+myret;
				rem='0';
			}
		}if(lng[n-1-i]!=shrt[n-1-i]){
			if(rem=='0'){
				myret="1"+myret;
			}else{
				myret="0"+myret;
			}
		}if(lng[n-1-i]=='1' and shrt[n-1-i]=='1'){
			if(rem=='0'){
				myret="0"+myret;
				rem='1';
			}else{
				myret="1"+myret;
			}
		}
	}
	if(rem=='1'){
		myret="1"+myret;
	}
	return myret;
}

static string bmod(string str, int n){
	if(str.length()<n){
		cout<<str<<" is shorter than "<<n<<endl;
		return "";
	}
	string temp=str.substr(str.length()-n,n);
	return temp;
}

static string breverse(string str){
	string ret=str;
	for(int i=0;i<str.length();i++){
		ret[i]=str[str.length()-1-i];
	}
	return ret;
}

static string lbshift(string str, int n){
	string temp=str;
	for(int i=0;i<n;i++){
		temp=temp.substr(1,temp.length()-1)+"0";
	}
	return temp;
}

static string rbshift(string str, int n){
	string temp=breverse(str);
	for(int i=0;i<n;i++){
		temp=temp.substr(1,temp.length()-1)+"0";
	}
	return breverse(temp);
}

static string rrot(string str, int n){
	return (bor(rbshift(str,n),lbshift(str,str.length()-n)));
}

static string choice(string str1, string str2,string str3 ){
	return bxor(band(str1,str2),band(complement(str1),str3));
}

static string maj(string str1, string str2,string str3 ){
	return bxor(bxor(band(str1,str2),band(str1,str3)),band(str2,str3));
}

static string SIG0(string str){
	return bxor(bxor(rrot(str,2),rrot(str,13)),rrot(str,22));
}

static string SIG1(string str){
	return bxor(bxor(rrot(str,6),rrot(str,11)),rrot(str,25));
}

static string sig0(string str){
	return bxor(bxor(rrot(str,7),rrot(str,18)),rbshift(str,3));
}

static string sig1(string str){
	return bxor(bxor(rrot(str,17),rrot(str,19)),rbshift(str,10));
}

// MESSAGE COMPLETION

static int STRINGnum0(string str){
	int l = str.length()*8;//bitwise, "abc" is 3x8bit (3 octets/bytes)
	int k =(448-l-1)%512;
	if(k<0){
		k=k+512;
	}
	return k;
}

static int num0(int l){
	int k =(448-l-1)%512;
	if(k<0){
		k=k+512;
	}
	return k;
}

static string bourage(string str){
	string ret = tobit(str);
	int len = ret.length();
	int n = num0(len);
	ret=ret+"1";
	for(int i = 0;i<n;i++){
		ret=ret+"0";
	}
	string binlen="";
	long long unsigned int len64=len;//sure to be 64 bit long
    long long          int c;
    long long unsigned int k;
	
	for (c = 63; c >= 0; c--)
    {
        k = len64 >> c;

        if (k & 1)
            binlen=binlen+"1";
        else
            binlen=binlen+"0";
    }
	ret = ret + binlen;
	return ret;
}

static string myhash(string str){
	string myM = bourage(str);
	
	
	int N=myM.length()/512;
	
	int offset =0;
	string M[N][16];
	
	for(int bloc=0;bloc<N;bloc++){
		for(int word=0;word<16;word++){
			M[bloc][word]=myM.substr(offset,32);
			offset=offset+32;
		}
	}
	
	unsigned long k[64] = {
		0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,
		0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,
		0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,
		0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
		0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,
		0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,
		0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,
		0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
		0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,
		0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,
		0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
	};
	string K[64];
	for(int t=0;t<64;t++){
		K[t]=hextobit(k[t]);
		cout<<K[t]<<endl;
	}
	
	unsigned long static H0 = 0x6a09e667;
	unsigned long static H1 = 0xbb67ae85;
	unsigned long static H2 = 0x3c6ef372;
	unsigned long static H3 = 0xa54ff53a;
	unsigned long static H4 = 0x510e527f;
	unsigned long static H5 = 0x9b05688c;
	unsigned long static H6 = 0x1f83d9ab;
	unsigned long static H7 = 0x5be0cd19;
	
	string W[64];
	
	string a;
	string b;
	string c;
	string d;
	string e;
	string f;
	string g;
	string h;
	
	string sh0;//string Hi
	string sh1;
	string sh2;
	string sh3;
	string sh4;
	string sh5;
	string sh6;
	string sh7;
	
	string T1;
	string T2;
	
	sh0=grow(hextobit(H0),32);
	sh1=grow(hextobit(H1),32);
	sh2=grow(hextobit(H2),32);
	sh3=grow(hextobit(H3),32);
	sh4=grow(hextobit(H4),32);
	sh5=grow(hextobit(H5),32);
	sh6=grow(hextobit(H6),32);
	sh7=grow(hextobit(H7),32);
	
	for(int i=1;i<N+1;i++){
		for(int t=0;t<16;t++){
			W[t]=M[i-1][t];
		}
		for(int t=16;t<64;t++){
			W[t]=bmod(bplus(bmod(bplus(bmod(bplus(sig1(W[t-2]),W[t-7]),32),sig0(W[t-15])),32),W[t-16]),32);
		}
		a=sh0;
		b=sh1;
		c=sh2;
		d=sh3;
		e=sh4;
		f=sh5;
		g=sh6;
		h=sh7;
		cout<<"len : "<<sh0.length()<<endl;
		for(int t=0;t<64;t++){
			T1=bmod(bplus(bmod(bplus(bmod(bplus(bmod(bplus(h,SIG1(e)),32),choice(e,f,g)),32),K[t]),32),W[t]),32);
			T2=bmod(bplus(SIG0(a),maj(a,b,c)),32);
			h=g;
			g=f;
			f=e;
			e=bmod(bplus(d,T1),32);
			d=c;
			c=b;
			b=a;
			a=bmod(bplus(T1,T2),32);
		}
		sh0=bmod(bplus(a,sh0),32);
		sh1=bmod(bplus(b,sh1),32);
		sh2=bmod(bplus(c,sh2),32);
		sh3=bmod(bplus(d,sh3),32);
		sh4=bmod(bplus(e,sh4),32);
		sh5=bmod(bplus(f,sh5),32);
		sh6=bmod(bplus(g,sh6),32);
		sh7=bmod(bplus(h,sh7),32);
		 
	}
	
	cout<<"sh0: "<<sh0<<" hex : "<<bintohex(sh0)<<endl;
	
	return bintohex(sh0)+bintohex(sh1)+bintohex(sh2)+bintohex(sh3)+bintohex(sh4)+bintohex(sh5)+bintohex(sh6)+bintohex(sh7);
}

int main(int argc, char **argv)
{
	cout <<myhash("Ella Richardeau")<<endl;
	//cout<<bintohex("11111111111111111111111111111111")<<endl;
	/*string str ="1";
	for(int i=0;i<61;i++){
		str=str+"1";
	}
	cout<<str.length()<<endl;
	cout<< (bourage("1"))<<endl<<bourage("1").length();
	*/
	return 0;
}