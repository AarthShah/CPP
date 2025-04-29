#include <iostream>
#include <string.h>
using namespace std;
class Book{
	private:
	   char* Title;
	   char* Author;
	   int page_count;
	   bool format_type;
	   float* chapter_pg;
	   int chapter_number;
	public:
		Book(){
		    cout<<"default constructor"<<endl;
			Title=new char[1];
			Title[0]='\0';
			Author=new char[1];
			Author[0]='\0';
			page_count=0;
			format_type=false;
			chapter_pg=0;
			chapter_number=0;
		}
		Book(const char* t, const char* a, int pages, bool format, float* chap_pg,int chap_num)
		{   cout<<"parameter constructor"<<endl;
			Title=new char[strlen(t)+1];
			strcpy(Title,t);
			
			Author=new char[strlen(a)+1];
			strcpy(Author,a);
			
			page_count=pages;
			format_type=format;
			chapter_number=chap_num;
			chapter_pg= new float[chap_num];
			for (int i = 0; i < chap_num; i++) {
            chapter_pg[i] =chap_pg[i];
        }
		}
		
		Book(const Book &obj){
		    cout<<"copy constructor"<<endl;
			Title=obj.Title;
			Author=obj.Author;
			page_count=obj.page_count;
			format_type=obj.format_type;
			chapter_pg=obj.chapter_pg;
			chapter_number=obj.chapter_number;
		}
		
		void setChapterpagecount(int x){
			page_count=x; 
		}
		
		void getinfo(){
		    
			cout<<"Book Name :"<<Title << endl; 
			cout<<"Author Name :"<<Author <<endl;
			cout<<"Page Count :"<<page_count<<endl;
			cout<<"is it Hardcover : ";
			if(format_type == 1){
				cout<<"YES" <<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
			cout<<"number of chapters :" <<chapter_number<<endl;
			cout<<"Chapter Pages :";
			for(int i=0;i<chapter_number;i++){
				cout<<chapter_pg[i];
			    cout<<"  ";
			}
			cout<<endl<<endl;
		}
		
		~Book(){
			    cout<<"destructor called"<<endl;
			    delete Title;
			    delete Author;
			    delete chapter_pg;
			    }
};
int main() {
	Book b1;
	b1.getinfo();
	float arr[20]={10,11,12,13,14,15,16,17,18,19};
	Book b2("BOOK","Haris",121,true,arr,10);

	b2.getinfo();
	Book b3=b2;
	b3.setChapterpagecount(500);
	b3.getinfo();
}
