#include<iostream>
#include<conio.h>
#include <windows.h>
#include<fstream>
#include<cstring>
#include<string.h>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include <unistd.h>
using namespace std ;
fstream file ;

#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

void MainMenu();
void mobileMain();
class Mobile ;
void interface1(Mobile*,Mobile,int);
void interface2(Mobile*,int);
void displayheading() ;
long int fileSize() ;
int numOfMobiles() ;
string time() ;





const unsigned char BLACK = 219;
BOOL gotoxy(const WORD x, const WORD y) {
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
void LoadingProcess()
{
    int x = 5, y = 9;

    COORD coord;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    
    cout<<"Please wait....";
    x = 5, y = 10;

    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    int r ;
    for(r = 1; r <= 20; r++)
    {
        int q ;
        for(q = 0; q <= 10000000; q++);
        cout<<"" << (char)177 ;
    }
    system("cls");
}

int nextValue(fstream &file)
{
	int value=0 ;
	file >> value ;
	return value ;
}

void increment()        // increment the total number of phones
{
	int current; 
	file.open("Data.txt" ,  ios::out | ios::in) ;
	try
	{
		if(!file.is_open())			{		throw 'k'; 		}    // if file does'nt exist
		current = nextValue(file) ; 			 				// Find the Total num of current Phones			
		current += 1 ;											//Add 1 to the total 
		file.seekp(0) ;											// move file pointer to the beginning
		file << current ;										// Write the incremented value in the file
		file.close();	
	}
	catch(...)
	{
		cout<<"FIlE OPENING ERROR!\n"<<endl;
		system("pause");
	}
}
void decrement()        // decrement the total number of phones
{
	int current; 
	file.open("Data.txt" ,  ios::out | ios::in) ;
	try
	{
		if(!file.is_open())			{		throw 'k'; 		}    // if file does'nt exist
		current = nextValue(file) ; 			 				// Find the Total num of current Phones			
		current -= 1 ;											//Add 1 to the total 
		file.seekp(0) ;											// move file pointer to the beginning
		file << current ;										// Write the incremented value in the file
		file.close();	
	}
	catch(...)
	{
		cout<<"FIlE OPENING ERROR!\n"<<endl;
		system("pause");
	}	
}


										//MOBILE CLASS
class Mobile
{
	protected:
	int ID ;
	string Brand; 		//(Samsung,Apple,Huawei,Infinix)(0-3)
	string Purpose; 		//(Photography,Home,Gaming)(0-2)
	string Processor; 	//(Core,Dual Core,Quad Core,Octa Core)(0-3)
	int Battery_Life; 		//Average Battery Life
	int Screen_Size; 
	int Storage; 			//Rom	//Amount of data it can hold
	int Ram; 				//Amount of memory it has to utilise
	int Camera_Quality; 
	double Price;
	int Quantity;
	
	
	public:
	
	Mobile(){	          //Constructor
		ID=100 ;
		Brand =" " ;
		Purpose= " ";
		Processor=" " ;
		Battery_Life=0;
		Screen_Size=0;
		Storage=0;
		Ram=0;
		Camera_Quality=0;
		Price=0;
		Quantity= 00 ;
	}
	
	
	void set_ID(int ID)								{this->ID = ID;}
	int get_ID(void) const							{return ID;}
	
	void set_Quantity(int Quantity)					{this->Quantity = Quantity;}
	int get_Quantity(void) 							{return Quantity;}
	
	void set_Brand(string Brand)					{this->Brand = Brand;}
	string get_Brand(void) const					{return Brand;}
	
	void set_Purpose(string Purpose)				{this->Purpose = Purpose;}
	string get_Purpose(void) 						{return Purpose;}
	
	void set_Processor(string Processor)			{this->Processor = Processor;}
	string get_Processor(void) const				{return Processor;}
	
	void set_Battery_Life(int Battery_Life)			{this->Battery_Life = Battery_Life;}
	int get_Battery_Life(void) const				{return Battery_Life;}
	
	void set_Screen_Size(int Screen_Size)			{this->Screen_Size = Screen_Size;}
	int get_Screen_Size(void) const					{return Screen_Size;}
	
	void set_Storage(int Storage)					{this->Storage = Storage;}
	int get_Storage(void) const						{return Storage;}
	
	void set_Ram(int Ram)							{this->Ram = Ram;}
	int get_Ram(void) const							{return Ram;}
	
	void set_Camera_Quality(int Camera_Quality)		{this->Camera_Quality = Camera_Quality;}
	int get_Camera_Quality(void) const				{return Camera_Quality;}
	
	void set_Price(double Price)					{this->Price = Price;}
	double get_Price(void) const					{return Price;}
	
	
	
	void operator =(Mobile c)     //Overloaded Operator  Mobile1 = Mobile2  
	{
		ID = c.ID;
		Brand = c.Brand ;
		Purpose= c.Purpose;
		Processor= c.Processor ;
		Battery_Life= c.Battery_Life;
		Screen_Size= c.Screen_Size;
		Storage= c.Storage;
		Ram= c.Ram;
		Camera_Quality=c.Camera_Quality;
		Price= c.Price;
		Quantity= c.Quantity ;
	} 
	
    void TransferData(fstream &file)   // Load Data From File into member variables
	{       
		ID = nextValue(file) ;
		NextBrand( nextValue(file) );
		NextProcessor( nextValue(file) ) ;
    	NextPurpose( nextValue(file) );
        Battery_Life= nextValue(file)  ;
        Screen_Size=nextValue(file) ;
        Storage=nextValue(file);
        Ram= nextValue(file);
        Camera_Quality= nextValue(file);
        Price =nextValue(file) ;
        Quantity= nextValue(file);
	}
	
	void Showall()
	{
	cout<<"\nID: "<<ID<<"\nQuantity: "<<Quantity<<" Pieces"<<"\nBattery: "<<Battery_Life<<" Hours"<<"\nBrand: "<<Brand<<"\nCamera_Quality: "<<Camera_Quality<<" Mega-Pixels"<<"\nPrice: Rs "<<Price<<" /-"<<"\nProcessor: "<<Processor<<"\nPurpose: "<<Purpose<<" Use"<<"\nRam: "<<Ram<<" GB"<<"\nScreen_Size: "<<Screen_Size<<" Inches"<<"\nStorage: "<<Storage<<" GB"<<endl;	
	}
	
	void  NextBrand(int x) { //SET SUB-MENU
	
		if(x==0)
		{
			Brand="Samsung";
		}
		else if(x==1)
		{
			Brand="Apple" ;
		}
		else if(x==2)
		{
			Brand="Huawei" ;
		}
		else if(x==3)
		{
			Brand="Infinix" ;
		}
			
	}
	void  NextProcessor(int x) { //SET SUB-MENU
	
			if(x==0)
		{
			Processor="Core";
		}
		else if(x==1)
		{
			Processor="Dual-Core" ;
		}
		else if(x==2)
		{
			Processor="Quad-Core" ;
		}
		else if(x==3)
		{
			Processor="Octa-Core" ;
		}	
	}
	void  NextPurpose(int x) {		//SET SUB-MENU	
		if(x==0)
		{
			Purpose="Photography";
		}
		else if(x==1)
		{
			Purpose="Home" ;
		}
		else if(x==2)
		{
			Purpose="Gaming" ;
		}
	}
	string getPurpose1(int x){
			if(x==0)
		{
			return "Photography" ; 
		}
		else if(x==1)
		{
			return "Home" ;
		}
		else if(x==2)
		{
			return "Gaming" ;
		}
	}
	string getBrand1(int x){
		if(x==0)
		{
			return ("Samsung") ;
		}
		else if(x==1)
		{
			return ("Apple") ;
		}
		else if(x==2)
		{
				return ("Huawei") ;
		}
		else if(x==3)
		{
			return ("Infinix") ;
		}	
	}
	string getProcessor1(int x){
		if(x==0)
		{
			return ("Core") ;
		}
		else if(x==1)
		{
			return ("Dual-Core") ;
		}
		else if(x==2)
		{
				return ("Quad-Core") ;
		}
		else if(x==3)
		{
			return ("Octa-Core") ;
		}	
	} 
    int getBT1(int x){
		int BL[4]={8,12,14,20} ;
		return BL[x] ;
	}
	int getSize1(int x){
		int ScreenSize[]={5,6,8,10} ;
		return ScreenSize[x] ;
	}
	int getStorage1(int x){
		int storage[5]={8,16,32,64,128};
		return storage[x];
	}
	int getRAM1(int x){
		int ram[3]= {2,4,8};
		return ram[x];
	}
	int getCamera_Quality1(int x){
		int CQ[5]={8,12,18,24,36} ;
		return CQ[x] ;
	}
     
     void purposeMenu();
     void BrandMenu();
     void processorMenu();
     void sizeMenu();
     void StorageMenu();
     void ramMenu();
     void btMenu();
     void CameraQualityMenu();
     friend Mobile defaultt(Mobile m);  
     void printFilteredMobiles(Mobile*,Mobile,int);
     int getFilteredMobiles(Mobile*, Mobile, int );
};

Mobile defaultt(Mobile m) 	//friend function to assign default values
{
		m.Brand =" " ;
		m.Purpose= " ";
		m.Processor=" " ;
		m.Battery_Life=0;
		m.Screen_Size=0;
		m.Storage=0;
		m.Ram=0;
		m.Camera_Quality=0;
		m.Price=0;
		return m ;
}

void mobileMain()
{
    fstream fptr ;
    fptr.open( "Data.txt" ,ios::in );
    try
    {	
		if(!fptr.is_open()) {throw 'k' ;}        // If file is Doesn't exist 
		
		int Mobsize = nextValue(fptr) ;
		Mobile mob[Mobsize] ;                			 // creates an array of objects , MOBSIZE=total number of mobiles in system
	
		int fptr_i ;  //Row By Row
		for(fptr_i=0;fptr_i<Mobsize ; fptr_i++)
   	 	{
        	mob[fptr_i].TransferData(fptr) ;
    	}
    	fptr.close() ;
    
    	Mobile filter,test ;
    
    	int user_input= -1 ;
    	int input_type= 1 ;
    	interface1(mob,filter,Mobsize);
    
    	while(user_input!=0)
    	{
    		if(user_input!=11) 
			{  
			 	cin >> user_input ;
				if( cin.fail() ) {  throw 1 ;  }
			}
    		else	{   user_input++ ; 	}
		 	
			user_input *= input_type;
		 	
		switch(user_input)
		{
			
			case 12:
				interface1(mob,filter,Mobsize);
			break ;
			
			case 9000000000:// Back to Main Menu
			case 900000000:// Back to Main Menu
			case 90000000:// Back to Main Menu
			case 9000000: //Back to Main Menu
			case 900000:// Back to Main Menu
			case 90000:// Back to Main Menu
			case 9000:// Back to Main Menu
			case 900:// Back to Main Menu
			case 90:// Back to Main Menu
				input_type = 1 ;
				interface1(mob,filter,Mobsize);
			break ;	
					
				
			case 1: // SHOW ALL MobileS
				filter.printFilteredMobiles(mob,filter, Mobsize) ;
				getch();
				interface1(mob,filter,Mobsize) ;
				input_type=1 ;
			break;		
			
			case 2:  // Filter By Purpose
				filter.purposeMenu();
				input_type=10; //10
			break;
			
			case 10:// Filter By Purpose->Photography
			case 20:// Filter By Purpose->Home
			case 30:// Filter By Purpose->Gaming
				filter.set_Purpose(	filter.getPurpose1(((user_input/input_type)-1)	) );
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 80:// Clear Filter
				filter.set_Purpose(" ");
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 120:
				filter.purposeMenu();
			break;
	
			case 3: // Filter By Brand
				filter.BrandMenu();
				input_type=100; 			//100
			break ;
			
			case 100:// Filter By BRAND->SAMSUNG
			case 200:// Filter By BRAND->APPLE
			case 300:// Filter By BRAND->HUAWEI
			case 400:// Filter By BRAND->INFINIX
				filter.set_Brand(	filter.getBrand1(((user_input/input_type)-1) ) );
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 800: // Clear Filter
				filter.set_Brand(" ");
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 1200:
				filter.BrandMenu();
			break;
			
			case 4: // Filter By Storage
				filter.StorageMenu();    
				input_type=1000 ; 				//1k    
			break ;	
			
			case 1000:// Filter By Storage->8
			case 2000:// Filter By Storage->16
			case 3000:// Filter By Storage->32
			case 4000:// Filter By Storage->64
			case 5000:// Filter By Storage->128
				filter.set_Storage(	filter.getStorage1( ( (user_input/input_type)-1 ) ) );
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 8000:// Clear Filter
				filter.set_Storage(0) ;
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
				
			case 12000:
					filter.StorageMenu();    
			break;
			
			case 5: //Filter By Battery 
				filter.btMenu(); 
				input_type=10000; 				//10k
			break ;	
			
			case 10000:// Filter By Battery->8
			case 20000:// Filter By Battery->12
			case 30000:// Filter By Battery->14
			case 40000:// Filter By Battery->20
				filter.set_Battery_Life(	filter.getBT1( ( (user_input/input_type)-1   )   ) );
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 80000:// Clear Filter
				filter.set_Battery_Life(0) ;
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 120000:
				filter.btMenu();
			break ;	
				
			
			case 6: //Filter By screen Size
				filter.sizeMenu(); 
				input_type= 1000000 ;    // 1 Million
			break ;	
			
			case 1000000: // Filter By Screen Size -> 5
			case 2000000: // Filter By Screen Size -> 6
			case 3000000: // Filter By Screen Size -> 8
			case 4000000: // Filter By Screen Size -> 10
				filter.set_Screen_Size(	filter.getSize1( ( (user_input/input_type)-1   )   ) );
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
				
			case 8000000: // Clear Filter
				filter.set_Screen_Size(0) ;
				interface1(mob,filter,Mobsize) ;
				input_type=1;
			break;
			
			case 12000000:
				filter.sizeMenu(); 
			break;
			
			
			
			case 7: //Filter By Ram
				filter.ramMenu(); 
				input_type=100000;  // 1 LAKH
			break ;
			
			case 100000:// Filter By RAM->2
			case 200000:// Filter By RAM->4
			case 300000:// Filter By RAM->8
				filter.set_Ram(	filter.getRAM1( ( (user_input/input_type)-1   )   ) );
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 800000:// Clear Filter
				filter.set_Ram(0) ;
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 1200000:
				filter.ramMenu(); 
			break;


			case 13: //Filter By Camera Quality
				filter.CameraQualityMenu(); 
				input_type = 10000000;  // 10 MILLION
			break ;
			
			case 10000000:// Filter By Camera->8
			case 20000000:// Filter By Camera->12
			case 30000000:// Filter By Camera->18
			case 40000000:// Filter By Camera->24
			case 50000000:// Filter By Camera->36
				filter.set_Camera_Quality(	filter.getCamera_Quality1( ( (user_input/input_type)-1   )   ) );
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 80000000:// Clear Filter
				filter.set_Camera_Quality(0) ;
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 120000000:
				filter.CameraQualityMenu(); 
			break;
			
			
			case 14: //filter by processor
				filter.processorMenu();
				input_type=100000000; // 10 crore=100 million
			break ;	
			
			case 100000000: // Processor -> Core
			case 200000000: // Processor -> Dual-Core
			case 300000000: // Processor -> Quad-Core
			case 400000000: // Processor -> Octa-Core
				filter.set_Processor(	filter.getProcessor1(((user_input/input_type)-1) ) );
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break;
			
			case 800000000: //Clear filter
				filter.set_Processor(" ");
				interface1(mob,filter,Mobsize) ;
				input_type = 1;
			break ;	
			
			case 1200000000:
				filter.processorMenu();
			break;

			case 8:  //Clear everything filter
				filter = defaultt(filter) ; 		//friend function
				interface1(mob,filter,Mobsize) ;
				input_type=1;
			break ;	
			
			case 0: //Exit Mode
				MainMenu();
			break ;	
			
			default:
				user_input=11 ;
				cout<<"Invalid Input!!!"<<endl ;
				getch();
			break ;					
			} 		
		}
	}
	catch(char)
	{
			cout<<"Cannot open File" ;
			system("Pause") ;
			MainMenu() ;		
	}
	catch(int)
	{
			cout<<"Invalid Input!\nPlease Enter a valid integer\n" ;
			system("Pause") ;
			system("Pause") ;
			cin.clear() ;
			cin.ignore(1000,'\n') ;
			mobileMain() ;
	}

}

void Mobile::purposeMenu()  {  
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Mobile Selector\n\t\tFiltering Mobile by Purpose of use\n\nChoose an option from below:";
	int index=0;
	for(index; index<3;)
		cout<<"\n"<<++index<<")"<<getPurpose1(index)<<" Use";
	cout<<"\n\n8) Any.";
	cout<<"\n------------------";
	cout<<"\n9) Back to Main Menu.\n\n";	
	cout<<"\n0) Exit.\n\n";
}

void Mobile::BrandMenu() {
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Brand Selector\n\t\tFiltering Mobiles by Brand Name\n\nChoose an option from below:";
	int index=0;
	for(index; index<4;)
		cout<<"\n"<<++index<<")"<<getBrand1(index);
	cout<<"\n\n8) Any.";
	cout<<"\n------------------";
	cout<<"\n9) Back to Main Menu.\n\n";	
	cout<<"\n0) Exit.\n\n";
}

void Mobile::processorMenu() {
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Mobile Selector\n\t\tFiltering Mobile by Processor.\n\nChoose an option from below:";
	int index=0;
	for(index; index<4;)
		cout<<"\n"<<++index<<")"<< getProcessor1(index);
	cout<<"\n\n8) Any.";
	cout<<"\n------------------";

	cout<<"\n9) Back to Main Menu.\n\n";	
	cout<<"\n0) Exit.\n\n";
}

void Mobile::sizeMenu(){
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Mobile Selector\n\t\tFiltering Mobile by Screen Size.\n\nChoose an option from below:";
	int index=0;
	for(index; index<4;)
		cout<<"\n"<< ++index<<")"<< getSize1(index)<<" inches";
	cout<<"\n\n8) Any.";
	cout<<"\n------------------";
	
	cout<<"\n9) Back to Main Menu.\n\n";	
	cout<<"\n0) Exit.\n\n";
}

void Mobile::StorageMenu(){
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Mobile Selector\n\t\tFiltering Mobiles by Hard Disk.\n\nChoose an option from below:";
	int index=0;
	for(index; index<5;)
		cout<<"\n"<< ++index<<")"<< getStorage1(index)<<" GB";
	cout<<"\n\n8) Any.";
	cout<<"\n------------------";

	cout<<"\n9) Back to Main Menu.\n\n";	
	cout<<"\n0) Exit.\n\n";	
}

void Mobile::ramMenu(){
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Mobile Selector\n\t\tFiltering Mobile by RAM.\n\nChoose an option from below:";
	int index=0;
	for(index; index<3;)
		cout<<"\n"<< ++index<<")"<< getRAM1(index)<<" ram" ;
	cout<<"\n\n8) Any.";
	cout<<"\n------------------";

	cout<<"\n9) Back to Main Menu.\n\n";	
	cout<<"\n0) Exit.\n\n";
}

void Mobile::btMenu(){
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Mobile Selector\n\t\tFiltering Mobile by Battery Life.\n\nChoose an option from below:";
	int index=0;
	for(index; index<4;)
		cout<<"\n"<< ++index<<")"<< getBT1(index)<<" Hours";
	cout<<"\n\n8) Any.";
	cout<<"\n------------------";

	cout<<"\n9) Back to Main Menu.\n\n";	
	cout<<"\n0) Exit.\n\n";
}

void Mobile::CameraQualityMenu(){
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Mobile Selector\n\t\tFiltering Mobile by Camera Quality.\n\nChoose an option from below:";
	int index=0;
	for(index; index<5;)
		cout<<"\n"<< ++index<<")"<< getCamera_Quality1(index)<<" Mega-Pixels";
	cout<<"\n\n8) Any.";
	cout<<"\n------------------";

	cout<<"\n9) Back to Main Menu.\n\n";	
	cout<<"\n0) Exit.\n\n";
}

void Mobile :: printFilteredMobiles(Mobile *mob, Mobile filter, int total) {
	int index=0, count=0; 
	int printMobile = 0;
	Mobile filtered_Mobile[total];
	for(index; index<total; index++)
	 {
		printMobile = 1;
		
		if( (filter.get_Purpose().compare(" ")!=0) && filter.get_Purpose().compare(mob[index].get_Purpose()) !=0 )
			printMobile = 0;			

		if( (filter.get_Brand().compare(" ")!=0) && filter.get_Brand().compare(mob[index].get_Brand() )!=0 )
			printMobile = 0;

		if( (filter.get_Processor().compare(" ")!=0) && filter.get_Processor().compare(mob[index].get_Processor())!=0 )
			printMobile = 0;
			
		if(filter.get_Battery_Life() != 0 && filter.get_Storage() != mob[index].Storage)
			printMobile =0;
			
		if((filter.get_Storage() != 0 )&& filter.get_Storage() != mob[index].Storage)
			printMobile =0; 
		
		if((filter.get_Ram() != 0 )&& filter.get_Ram() != mob[index].Ram)
			printMobile =0; 
		
		if(filter.get_Screen_Size()!= 0 && filter.get_Screen_Size() != mob[index].Screen_Size)
			printMobile =0; 
			
		if(filter.get_Camera_Quality() != 0 && filter.get_Camera_Quality() != mob[index].Camera_Quality)
			printMobile =0; 

		if(printMobile) {
			filtered_Mobile[count] = mob[index];
			count++;
		}
	}
	cout<<"FILTERED COUNT: "<<getFilteredMobiles(mob,filter,total)<<endl ;
	interface2(filtered_Mobile,count);
}

int Mobile::getFilteredMobiles(Mobile *mob, Mobile filter, int total)
{
	int index=0, count=0; 
	int printMobile = 0;
	Mobile filtered_Mobile[total];
	for(index; index<total; index++)
	 {
		printMobile = 1;
		
		if( (filter.get_Purpose().compare(" ")!=0) && filter.get_Purpose().compare(mob[index].get_Purpose()) !=0 )
			printMobile = 0;			

		if( (filter.get_Brand().compare(" ")!=0) && filter.get_Brand().compare(mob[index].get_Brand() )!=0 )
			printMobile = 0;

		if( (filter.get_Processor().compare(" ")!=0) && filter.get_Processor().compare(mob[index].get_Processor())!=0 )
			printMobile = 0;
			
		if(filter.get_Battery_Life() != 0 && filter.get_Storage() != mob[index].Storage)
			printMobile =0;
		
			
		if((filter.get_Storage() != 0 )&& filter.get_Storage() != mob[index].Storage)
			printMobile =0; 
		
		if((filter.get_Ram() != 0 )&& filter.get_Ram() != mob[index].Ram)
			printMobile =0; 
		
		if(filter.get_Screen_Size()!= 0 && filter.get_Screen_Size() != mob[index].Screen_Size)
			printMobile =0; 
			
		if(filter.get_Camera_Quality() != 0 && filter.get_Camera_Quality() != mob[index].Camera_Quality)
			printMobile =0; 

		if(printMobile!=0 ) 
		{
			count++;
		}
	}
	return count ;
}


												//CUSTOMER CLASS
class customer 
{
	
	char Uname[20] , Password[20] ;
	char fname[30] , lname[30] ;
	public:
		
		void set_Uname(char *Uname1)			{strcpy(Uname,Uname1) ; }
		char* get_Uname(void) 					{return Uname ;}

		void set_Password(char *Password1 )		{strcpy(Password,Password1) ; }
		char* get_Password(void) 				{return Password;}

		void set_fname(char *fname1)			{strcpy(fname,fname1) ;}
		char* get_fname(void) 					{return fname;}

		void set_lname(char *lname1)			{strcpy(lname,lname1) ;}
		char* get_lname(void) 					{return lname;		}
		
	
		void user_access()  ;
		void login() 		;
		void regist() 		;
		void check_duplicate(char *s) ;
		
};

void customer::user_access()
{
	
	int n ;
	 system("CLS");
XY:
	cout<<"          --------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"          __________________________________________________________________________________________________________________________________________________\n\n";
    cout<<"                                                             ~ WELCOME TO USER CONTROL PANEL ~                                         \n\n" ;
    cout<<"          -------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"          ___________________________________________________________________________________________________________________________________________________";
    
    
    cout<<"\n\n\t\t\tM)ain Screen\t C)ontinue :\n" ;
	char u ;
	gotoxy(70, 10);
	cout<<"Choice: " ;
	cin >> u ;
	if(u=='m' || u=='M'){ MainMenu(); }
	else if(u!='m' && u!='M' && u!='c' && u!='C'){ cout<<"Invalid input\n" ; system("Pause"); user_access(); }
    
    
    
    
    gotoxy(70, 12);
    cout<<"1. LOGIN";
    gotoxy(70, 13);
    cout<<"2.REGISTER"; 
    gotoxy(70, 16);
    cout<<"ENTER YOUR CHOICE:  ";
    cin>>n ;
    try
    {
    	if(cin.fail()) {   	throw 1 ;  	}
		
    	switch(n)
    	{
    	case 1:
        	system("CLS");
        	login();   		//existing user
        break;
        
    	case 2:
        	system("CLS");
        	regist();  			//new user
        break;
        
    	default:
        	cout<<"\n\n\t\t\t\tNO MATCH FOUND";
        	cout<<"\n\n\t\t\tPress Enter to re-Enter the choice";
        if(getch()==13)
            system("CLS");
        goto XY;
    	}
    }
    catch(int)
    {
    		cout<<"Invalid Input!\nPlease Enter a valid integer\n" ;
			system("Pause") ;
			cin.clear() ;
			cin.ignore(1000,'\n') ;
			user_access() ;		
	}
}

void customer::login()
{
	system("cls") ;
    int i=0 , l=0 ;
    
    file.open("UserData.txt",ios::in) ;
    fstream out("LoginData.txt", ios::app);
	try
	{
		if( !file.is_open() ||  !out.is_open() )  {throw 'k' ; }
		
		
	
    	char name[30], pass[20], press, k;
    	int match = 0, usersignin = 0, z = 0;
    	char ch ,ph;

find:

    cout<<"          --------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"          __________________________________________________________________________________________________________________________________________________\n\n";
    cout<<"                                                             ~ WELCOME TO USER SIGN-IN PANEL ~                                         \n\n" ;
    cout<<"          -------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"          _________________________________________________________________________________________________________________________________________________\n\n\n";
    
	
//		fflush(stdin) ;
    	cout<<"\n\n\t\t\t\t  Enter Username(without spaces): ";
//    	char ph ;
		while(1)
    	{
        	ph = getch();
        	if(ph == ENTER)
        	{
            	break;
        	}
        	else if(ph == BKSP)
        	{
            	if(l > 0)
            	{
                l--;
                cout<<"\b \b";
           	 	}
        	}
        	else if(ph == TAB || ph == SPACE)
        	{
            	continue;
        	}
        	else
        	{
            name[l] = ph;
            l++;
            cout<<ph ;
        	}
    	}
    	cout<<"\n\n\t\t\t\t  Enter Password(without spaces): ";
    	
    	while(1)
    	{
        	ch = getch();
        	if(ch == ENTER)
        	{
            	break;
        	}
        	else if(ch == BKSP)
        	{
            	if(i > 0)
            	{
                i--;
                cout<<"\b \b";
           	 	}
        	}
        	else if(ch == TAB || ch == SPACE)
        	{
            	continue;
        	}
        	else
        	{
            pass[i] = ch;
            i++;
            cout<<"*" ;
        	}
    	}
    	file.read((char*)this,sizeof(*this));
    	while( file.eof()==0 ) 
    	{
        	if(((strcmp(Uname,name)) == 0 ) && ((strcmp(Password,pass)) == 0))
        	{
            match++ ;
			out.write((char*)this,sizeof(*this));  //write into login data
            out.close();
            system("CLS");
            LoadingProcess();
            system("CLS");
            cout<<"\n\n\n\n\t\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!\n";
            getch();
            system("CLS");
            file.close();
            mobileMain(); 
        	}
        	file.read((char*)this,sizeof(*this));
    	}
    		file.seekg(0,ios::beg) ;
    		if(match == 0)
    		{
        		system("CLS");
        		LoadingProcess();
        		system("CLS");
				char choice5;
        		cout<<"\n\n\n\t\t\tWRONG USERNAME OR PASSWORD!!";
        		cout<<"\n\n\t\t\t\t  (Press 'Y' to re-login or 'N' to exit)\n";
        		cin>>choice5;
				if(choice5=='y'|| choice5=='Y')
				{
        			system("CLS");
        			LoadingProcess();
        			system("CLS");
					file.close();
        			login();
				}
				else if(choice5=='n' || choice5=='N'){  MainMenu();}
    		}
    	
	} // end try 
    catch(char)
	{
	  	cout<<"File not found"<<endl ; 
	  	cout<<"\nNo REgistered Users at the moment!\n\n" <<endl; 
	  	system("Pause");
	  	MainMenu() ;
	}
	
    file.close();
    out.close();
		
}

void customer:: check_duplicate(char *s)
{
	ifstream iff("UserData.txt",ios::in);
	try
	{
		if(!iff.is_open()) {throw 'k' ; }
		
    	iff.read((char*)this,sizeof(*this)) ;
    	while(iff.eof()==0)
    	{
    		if((strcmp(s,Uname))==0) //check if username already exist
    		{
    			throw 1 ;
			}
			iff.read((char*)this,sizeof(*this));
		}
		iff.close();
	}
	catch(char)
	{
		cout<<"Unable to locate file!\n\n" ;
		system("pause") ;
	}
	catch(int)
	{
		cout<<"Account already exist!"<<endl;
    	cout<<"TRY AGAIN"<<endl;
    	getch();
    	user_access();
	}
		
}

void customer::regist()
{
	int count = 0, i = 0,n=0;
    char s, k;
    char ch[20] ;

    
	file.open("UserData.txt",ios::app ) ;
	try
	{
		if(!file.is_open() )  { throw 'k' ;}

    	cout<<"          --------------------------------------------------------------------------------------------------------------------------------------------------\n";
    	cout<<"          __________________________________________________________________________________________________________________________________________________\n\n";
    	cout<<"                                                             ~ WELCOME TO USER SIGN-UP PANEL ~                                         \n\n" ;
    	cout<<"          -------------------------------------------------------------------------------------------------------------------------------------------------\n";
    	cout<<"          __________________________________________________________________________________________________________________________________________________";
    
    	cin.ignore();
    	char str1[30] , str2[30] ;
    	gotoxy(70, 14);
    	fflush(stdin);
    	
fname11 :
    	cout<<"Enter First Name: ";
    	cin.getline(fname,30) ;
//VALIDATION FOR FIRST NAME
		long long int match =1 ;
		for(int b=0;b<strlen(fname);b++)
		{									// if user entered alphabets or space=32
			if( (fname[b] >=97 && fname[b] <=122 ) || (fname[b] >=65 && fname[b] <=90 )  ) 
			{
				match++ ;
			}
			else if( fname[b] == 32 || isdigit( fname[b] ) )  // if there's a digit or special char in the name
			{
				match *=100 ;  break ;
			}
		}
		if(match>=100) 
		{
			gotoxy(70, 15);
			cout<<"First Name cannot have spaces, digits and special charachters!\n\n" ;
			goto fname11 ;	
		}	
    	strcpy(str1,fname);
    	gotoxy(70, 17);
    	fflush(stdin);
    	
// VALIDATION FOR LAST NAME

lname11 :
    	cout<<"Enter last Name: ";
    	cin.getline(lname,30) ;
    	match =1 ; 
		for(int b=0;b<strlen(lname);b++)
		{											// if user entered alphabets or space=32
			if( (lname[b] >=97 && lname[b] <=122 ) || (lname[b] >=65 && lname[b] <=90 )  ) 
			{
				match++ ;
			}
			else if(lname[b]== 32 || isdigit( lname[b] ) )  // if there's a digit or special char in the name
			{
				match *=100 ;  break ;
			}
		}
		if(match>=100) 
		{
			gotoxy(70, 18);
			cout<<"Last Name cannot have spaces, digits or special charachters!\n\n" ;
			goto lname11 ;	
		}
    	
    	strcpy(str2,lname);
    	gotoxy(70, 20);
    	
//validation for username

username11:
    	cout<<"Enter Username(Without Spaces): ";
    	cin.getline(ch,30) ; 
		char sss;
		 											// input name in temp variable
    	match =1 ; 
    	fflush(stdin) ;
		for(int b=0;b<strlen(ch);b++)
		{	
			sss=ch[b] ; 										// if user entered alphabets or space=32
			if( (ch[b] >=97 && ch[b] <=122 ) || (ch[b] >=65 && ch[b] <=90 )  ) 
			{
				match++ ;
			}
			else if( sss == 32 )   // if there's a digit or special char in the name
			{
				match *=100 ;  break ;
			}
		}
		if(match>=100) 
		{
//			gotoxy(70, 21);
			cout<<"User-Name cannot have spaces!\nPLEASE TRY AGAIN\n" ;
			cin.clear() ;
			goto username11  ;	
		}
    
    check_duplicate(ch) ;
    
	strcpy(Uname,ch) ;         // Copy entered username to Object's->UserName
	
	

    gotoxy(70, 23);
    cout<<"Enter Password : ";
    
    //gotoxy(87, 17);
    
while(1)
{
        k = getch();
        if(k == ENTER)
        {
            break;
        }
        else if(k == BKSP)
        {
            if(i > 0)
            {
                i--;
                cout<<"\b \b";
            }
        }

        else if(k == TAB || k == SPACE)
        {
            continue;
        }

        else
        {
            Password[i] = k;
            i++;
            cout<<"*" ;
        }
}

		strcpy(fname,str1); 
		strcpy(lname,str2) ;
	
   		 file.write(	(char*)this , sizeof(*this)	) ;

    	file.close() ;
    

    	gotoxy(70, 13);
    	cout<<"Press enter to continue\n";
    	if((s=getch())==13)
    	{
        system("CLS");
        LoadingProcess();
        system("CLS");

        gotoxy(65, 12);
        
        cout<<"YOU ARE SUCCESSFULLY REGISTERED "<<endl;
		system("pause");
        system("cls");
        gotoxy(65, 13);
        cout<<"\t\tLogin?";
        gotoxy(65, 15);
        
        while(n !=1 && n!=2)
        {
        	cout<<"\n> PRESS 1 FOR YES\t\t> PRESS 2 FOR NO\n\n\t\t\t\t";
			fflush(stdin) ;
        	cin>>n ;
		}
        switch(n)
        {
        	case 1 :
            	system("CLS");
            	LoadingProcess();
            	system("CLS");
            	login();
            break;
        	case 2:
            	system("CLS");
            	LoadingProcess();
            	system("CLS");
            	gotoxy(70, 12);
            	cout<<"THANK YOU FOR REGISTERING\n\n";
            	system("pause");
         		MainMenu();
			break;
       	 } 	//end switch
    	} 	// end if
    
	} // end try 
    catch(char)
	{
		cout<<"File not found"<<endl ; 
		system("pause") ;
	}
}

												//ADMIN CLASS
												
class admin : public Mobile 
{
	char password[50];
	char adminID[10];
	
	public:
		admin()
		{
			strncpy(password ,"1234",50);
			strncpy(adminID ,"mustafa",10);	
		}
		void adminlogin() ;
		void admin_main() ;
		void admin_menu() ;
		void view_all(admin*) ;
		void search(admin*) ;
		void add(int,int) ;
		void deletee();
		void registered() ;
		void admin_helper(int);
		void show_purchases() ;
		int unique_ID(admin ) ;
		void admin_total() ;
		
};


int admin:: unique_ID(admin a)   //assigns a unique id
{
	int id ;
	id= a.get_ID() ;
	return id ;
}

void admin:: show_purchases()
{
		system("cls");         
		cout<<"\t\t\t\t============================================"<<"\n";
		cout<<"\t\t\t\t\t\t  PURCHASES  "<<"\n";
		cout<<"\t\t\t\t============================================"<<"\n\n\n\n";
		
		customer c2 ;
		char temp[20] ;
		string read1[4] ;
		int a ;
		
		fstream f1 ;   f1.open("Purchases_Users.txt" ,ios::in  ) ;
		fstream f2 ;   f2.open("Purchases_Mobile1.txt",ios::in ) ;
		fstream f3 ;   f3.open("Purchases_Mobile2.txt",ios::in ) ;
		
		try
		{
			if( 	(!f1.is_open()) ||  (!f2.is_open() ) ||   (!f3.is_open() ) 	 ) {throw 'k'; }
			
			f1.read((char*)&c2 , sizeof(c2) ) ;	
			while(f1.eof()==0 && f2.eof()==0 && f3.eof()==0 )
			{	
				cout<<"........................\n\n\n"<<endl;	
				cout <<"BUYER DETAILS: \n" ;
				cout<<"\nName: "<<c2.get_fname()<<" "<<c2.get_lname()<<"\tUsename: "<<c2.get_Uname() <<"\tPass: "<<c2.get_Password() <<endl ;	

				cout <<"\nPRODUCT DETAILS: \n" ;
				getline(f2,read1[0]) ;  			cout<<"Time: "<<read1[0]<<endl ;
				getline(f2,read1[1]) ;				cout<<"\nBrand: "<<read1[1]<<endl ;
				getline(f2,read1[2]) ;				cout<<"Processor: "<<read1[2]<<endl ;
				getline(f2,read1[3]) ;   			cout<<"Purpose: "<<read1[3]<<endl ;
			
				a= nextValue(f3) ;	 	 			cout<<"ID: "<<a<<endl ;
				a= nextValue(f3) ; 					cout<<"Battery Life: "<<a<<endl ;
				a= nextValue(f3) ; 					cout<<"Screen-Size: "<<a<<endl ;
				a= nextValue(f3) ; 					cout<<"Storage: "<<a<<endl ;
				a= nextValue(f3) ; 					cout<<"RAM: "<<a<<endl ;
				a= nextValue(f3) ; 					cout<<"Camera-Quality: "<<a<<endl ;
				a= nextValue(f3) ; 					cout<<"Price: "<<a<<endl ;
				a= nextValue(f3) ; 					cout<<"Quantity: "<<a<<endl ;
				cout<<"........................\n\n\n"<<endl;
				f1.read((char*)&c2 , sizeof(c2) ) ;		
			}
			system("Pause") ;
		} // end try 
		catch(char)
		{
			cout<<"File Cannot Be opened!\n" ;
			system("pause") ;
		}
	
	 	f1.close() ;
		f2.close() ;
		f3.close() ;
}

void deduct(fstream &temp , admin *b , int total)
{
	try
	{
		if(total==0) { throw 'k' ;}
		
		temp << total <<endl ;
		for(int i=0;i<total;i++)
		{
	 		temp << b[i].get_ID() << " " ;
	 	
			if(	b[i].get_Brand().compare("Samsung")==0 ) 				{  temp << 0 <<" " ;  }
			else if(	b[i].get_Brand().compare("Apple")==0 )  		{  temp << 1 <<" " ;  }
			else if(	b[i].get_Brand().compare("Huawei")==0 )  		{  temp << 2 <<" " ;  }
			else if(	b[i].get_Brand().compare("Infinix")==0 )  		{  temp << 3 <<" " ;  }
		
			if(	b[i].get_Processor().compare("Core")==0 ) 						{  temp << 0 <<" " ;  }
			else if(	b[i].get_Processor().compare("Dual-Core")==0 )  		{  temp << 1 <<" " ;  }
			else if(	b[i].get_Processor().compare("Quad-Core")==0 )  		{  temp << 2 <<" " ;  }
			else if(	b[i].get_Processor().compare("Octa-Core")==0 )  		{  temp << 3 <<" " ;  }
		
			if(	b[i].get_Purpose().compare("Photography")==0 ) 				{  temp << 0 <<" " ;  }
			else if(	b[i].get_Purpose().compare("Home")==0 )  			{  temp << 1 <<" " ;  }
			else if(	b[i].get_Purpose().compare("Gaming")==0 )  			{  temp << 2 <<" " ;  }
		
	 		temp << b[i].get_Battery_Life() << " " ;
	 		temp << b[i].get_Screen_Size() << " " ;
	 		temp << b[i].get_Storage() << " " ;
	 		temp << b[i].get_Ram() << " " ;
	 		temp << b[i].get_Camera_Quality() << " " ;
	 		temp << b[i].get_Price() << " " ;
	 		temp << b[i].get_Quantity() << " " ;
	 		temp << endl ;
		}	
	}
	catch(char)
	{
		cout<<"THERE ARE NO RECORDS PRESENT AT THE MOMENT!\n\n" ;
		system("Pause") ;	
	}
	
}

void quantity(admin *a,int pID)
{
	
	int i,total_Rec ;

		total_Rec = numOfMobiles() ;   		// FIND THE TOTAL NUMBER OF MOBILES FOR LOOP
	try
	{
		if(total_Rec ==0 ) { throw 'k' ; } 
		
		for(i=0;i<total_Rec;i++)
		{
			if( pID==a[i].get_ID() )
			{
				break 	;
			}
		}
		a[i].set_Quantity(		a[i].get_Quantity() -1				) ;
		
		fstream temp("temp.txt",ios::out) ;
		
		if(!temp.is_open()) {throw 1 ;}
		
		deduct(temp ,a , total_Rec) ;
		temp.close() ;
		remove("Data.txt")  ;               // Delete the original file
		rename( "temp.txt" , "Data.txt") ;  //Rename the Temporary file	
	}
	catch(char)
	{
		cout<<"THERE ARE NO RECORDS PRESENT AT THE MOMENT!\n\n" ;
		system("Pause") ;
	}
	catch(int)
	{
		cout<<"Unable to open file\n\n" ;
		system("Pause") ;
	}	
	
}

void admin::admin_helper(int ID)
{
	
	fstream fptr ;
	fptr.open( "Data.txt" ,ios::in );
	try
	{
		if(!fptr.is_open()) {throw 'k' ;}
		
		int Mobsize = nextValue(fptr) ;
		admin a[Mobsize] ;                			 // creates an array of objects , MOBSIZE=total number of mobiles in system

		int fptr_i ;  //Row By Row
		for(fptr_i=0;fptr_i<Mobsize ; fptr_i++)
    	{
       	 	a[fptr_i].TransferData(fptr) ;
    	}
    	fptr.close() ;
	
		quantity(a,ID);	
	}
	catch(char)
	{
		cout<<"Cannot open File\n\n" ;
		system("pause");
	}
	
}
void admin::admin_menu() 
{
system("cls") ;	
system("color 02");  					// (0=Black Background) + (2=Green text)
cout<<"\t\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<"\n";
cout<<"\t\t\t\t\t\tMENU "<<"\n";
cout<<"\t\t\t\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd"<<"\n\n\n";

cout<<"\t 1.Add Mobile"<<"\n\n";
cout<<"\t 2.Delete Mobile"<<"\n\n";
cout<<"\t 3.Search Mobile"<<"\n\n";
cout<<"\t 4.Display all Mobile"<<"\n\n";
cout<<"\t 5.Show Registered Accounts"<<"\n\n";
cout<<"\t 6.Show Purchases "<<"\n\n";
cout<<"\t 7.Display Total Records "<<"\n\n";

cout<<"\t 0.Log-Out"<<"\n\n" ;
cout<<"\t\t\t\t YOUR CHOICE: " ;
}

void admin:: admin_main()
{
	
	fstream fptr ;
	fptr.open( "Data.txt" ,ios::in );
	
	try
	{
		if(!fptr.is_open()) {throw 'k' ;}	
		
		int Mobsize = nextValue(fptr) ;
		
		if(Mobsize==0) {throw 'y' ;} 
		
		admin a[Mobsize] ;                			 // creates an array of objects , MOBSIZE=total number of mobiles in system
	
		int fptr_i ;  //Row By Row
		for(fptr_i=0;fptr_i<Mobsize ; fptr_i++)
	    {
	        a[fptr_i].TransferData(fptr) ;
	    }
	    fptr.close() ;
		 	
		admin_menu() ;
		int x ;
		
		cin>>x ;
		if(cin.fail()) {throw 1 ;}

		switch(x)
		{
			case 1 :   add(	unique_ID(a[Mobsize-1])	 ,1	)	;		admin_main() ;			break;
			case 2 :  deletee(); 			admin_main() ;			break;
			case 3 :  search(a);			admin_main() ;			break;
			case 4 :  view_all(a);			admin_main() ;			break;
			case 5 :  registered() ;		admin_main() ;          break;
			case 6 :  show_purchases() ;	admin_main() ;          break;
			case 7 :  admin_total() ;		admin_main() ;          break;
			
			case 0 :  MainMenu() ;									break;
			default:  
				cout<<"Invalid Input!\nPlease select from(0-6)\n" ;
				getch() ;
			break ;	
		}	
	}
	catch(char x)
	{
		cout<<"DATA FILE DOES NOT EXIST! \n\n" ;
		cout<<">Redirecting to ADD MOBILES PANEL< " <<endl ;
		system("Pause") ;
		if(x == 'y')
		{
			add(100,1);
		}
		else
		{
			add(100,0) ;
		}
		admin_main() ;
	}
	catch(int)
	{
		cout<<"InValid Input\nPlease enter only digits!\n\n" ;
		system("Pause") ;
	}
	
}


void admin::admin_total()
{
	system("cls");         
	cout<<"\t\t\t\t============================================"<<"\n";
	cout<<"\t\t\t\t\t\tTotal Number of Phone Records "<<"\n";
	cout<<"\t\t\t\t============================================"<<"\n\n\n\n";
	
	cout<<endl<<"\t\t\tCurrently "<<numOfMobiles()<<" Mobile Records are present in the system!"<<endl ;
	system("Pause") ;
	
}

void admin::registered()
{
	int choice=1 ;
	customer c ;
	system("cls");         
	cout<<"\t\t\t\t============================================"<<"\n";
	cout<<"\t\t\t\t\t\tRegistered Accounts "<<"\n";
	cout<<"\t\t\t\t============================================"<<"\n\n\n\n";
	
	file.open("UserData.txt",ios::in) ;
	try
	{
		if(!file.is_open() )
	
		
		file.read((char*)&c , sizeof(c) ) ;
		while(file.eof()==0)
		{
			cout<<choice<<".\tNAME: " <<c.get_fname()<<" "<<c.get_lname()<<"\tUSERNAME: "<<c.get_Uname()<<"\tPASSWORD: "<<c.get_Password()<<endl ;
			file.read((char*)&c , sizeof(c) ) ;
			choice++ ;
		}
		cout<<"\n\n"<<endl ;
		system("Pause") ;
	}
	catch(char)
	{
		cout<<"\nFile not found\n"<<endl ;
		system("pause") ; 
	}
	
}

void invalid()
{
			cout<<"\nIn-Valid Input\nPlease enter only digits!\n"<<endl ;
			cout<<endl 	;
			cin.clear() ;
			cin.ignore(1000,'\n') ;	
}

void admin::add(int pID, int flag)
{
		system("cls");
		file.open("Data.txt",ios::app) ;    //CREATES A FILE(if it not exist)      
	try
	{
		if( !file.is_open() )  {throw 'k' ; }
		
		int choice ;
		cout<<"\t\t\t\t============================================"<<"\n";
		cout<<"\t\t\t\t\t\tADD MOBILE PANEL "<<"\n";
		cout<<"\t\t\t\t============================================"<<"\n";
		
		int choose[11] ;
		pID++ ;
		if(pID==128)
		{
			pID++ ;
		}
		choose[0]= pID ;
		cout<<"\n"<<endl;
//		Quantity
		cout<<"PRODUCT ID ASSIGNED AUTOMATICALLY!\nID: "<<choose[0]<<endl ;
		cout<<"\n"<<endl;
		
		cout<<"\nYou'll be shown the choices, please select from below: \n\n\n" ;
brand:		
		cout<<"Which BRAND : \n" ;
		cout<<"1.Samsung\t2.Apple\t3.Huawei\t4.Infinix\n" ;
		cout<<"\t\tCHOICE: " ;
		cin >> choose[1] ;	cout<<"\n"<<endl;
		
		if( cin.fail()  || choose[1]>4 || choose[1]<1 )
		{
			invalid() ;
		  	goto brand 	;
			    
		}
		cout<<"What's the Processor: \n" ;
processor:
		cout<<"1.Core\t2.Dual-Core\t3.Quad-Core\t4.Octa-Core\n" ;
		cout<<"\t\tCHOICE: " ;
		cin >> choose[2] ;	cout<<"\n"<<endl;
		
		if(cin.fail() || choose[2]>4 || choose[2]<1 )
		{
			invalid() ;
		  	goto processor ;    
		}
		
		cout<<"What PURPOSE : \n" ;
prurpose:		
		cout<<"1.Photography Speciality \t2.BEST FOR HOME USE\t3.GAMING USE\n" ;
		cout<<"\t\tCHOICE: " ;
		cin >> choose[3] ;	cout<<"\n"<<endl;
		
		if(cin.fail() || choose[3]>3 || choose[3]<1 )
		{
			invalid() ;
		  	goto prurpose ;    
		}
		
		cout<<"What's its Battery life: \n" ;
battery:
		cout<<"1.8 hours talk-time\t2.12 hours talk-time\t3.14 hours talk-time\t4.20 hours talk-time\n" ;
		cout<<"\t\tCHOICE: " ;
		cin >> choose[4] ;	cout<<"\n"<<endl;
		
		if(cin.fail() || choose[4]>4 || choose[4]<1 )
		{
			invalid() ;
		  	goto battery ;  
		}
		
		cout<<"What's the Screen-Size: \n" ;
screen:		
		cout<<"1.5 inches\t2.6 inches\t3.8 inches\t4.10 inches\n" ;
		cout<<"\t\tCHOICE: " ;
		cin >> choose[5] ;		cout<<"\n"<<endl;
		
		if(cin.fail() || choose[5]>4 || choose[5]<1 )
		{
			invalid() ;
		  	goto screen ;  
		}
		
		cout<<"How much Storage Capacity does it have: \n" ;
storage:		
		cout<<"1. 8 GB\t2. 16 GB\t3. 32 GB\t4. 64 GB\t5. 128 GB\n" ;
		cout<<"\t\tCHOICE: " ;
		cin >> choose[6] ;	cout<<"\n"<<endl;
		
		if(cin.fail() || choose[6]>5 || choose[6]<1 )
		{
			invalid() ;
		  	goto storage ;  
		}
		cout<<"How much RAM does it posses: \n" ;
ram:		
		cout<<"1. 2 GB\t2. 4 GB\t3. 8 GB\n" ;
		cout<<"\t\tCHOICE: " ;
		cin >> choose[7] ;	cout<<"\n"<<endl;
		
		if(cin.fail() || choose[7]>3 || choose[7]<1 )
		{
			invalid() ;
		  	goto ram ;    
		}
		
		cout<<"What's its main Camera Quality:\n" ;
camera:		
		cout<<"1. 8 Mega Pixels\t2. 12 Mega Pixels\t3. 18 Mega Pixels\t4. 24 Mega Pixels\t5. 36 Mega Pixels\n" ;
		cout<<"\t\tCHOICE: " ;
		cin >> choose[8] ;		cout<<"\n"<<endl;
		
		if(cin.fail() || choose[8]>5 || choose[8]<1 )
		{
			invalid() ;
		  	goto camera ;    
		}
		cout<<"How much does it cost:" ;
price:		
		cin>> choose[9] ;	cout<<"\n"<<endl;
		
		if(cin.fail() )
		{
			invalid() ;
		  	goto price ; 
		}
		
		cout<<"How many pieces are there?(1-99)\t" ;
quantity:		
		cin >> choose[10] ;		cout<<"\n"<<endl;
		
		if(cin.fail() || choose[10]>=100 || choose[10]<=0 )
		{
			invalid() ;
		  	goto quantity ;    
		}
//WRITE INTO FILE -----------------------------	
		
		if(flag==0)
		{
			file << 1 <<endl ;
		}
		file <<choose[0]<<" " ;
		choose[1] -=1 ; file <<choose[1]<<" " ;
		choose[2] -=1 ; file <<choose[2]<<" " ;
		choose[3] -=1 ;	file <<choose[3]<<" " ;
		file << getBT1(choose[4]-1) <<" " ;
		file << getSize1(choose[5]-1) <<" " ;
		file << getStorage1(choose[6]-1) <<" " ;
		file << getRAM1(choose[7]-1) <<" " ;
		file <<getCamera_Quality1( choose[8]-1 )<<" " ;
		file <<choose[9]<<" " ;
		file << choose[10]<<" " ;
//--------------------------------------------------		
		file.close() ;
		if(flag!=0)
		{
			increment() ;
		}
        cout<<"\n\nRecord AddedSuccesfully! \n\n" ;
        system("Pause") ;
			
	}	// end try
	catch(char)
	{
		cout<<"\n\nFIlE OPENING ERROR!\n\n"<<endl;
		system("Pause") ;
	}	
}

void admin::deletee()
{
	system("cls");
	cout<<"\t\t\t\t============================================"<<"\n";
	cout<<"\t\t\t\t\t\tDELETE RECORD PANEL "<<"\n";
	cout<<"\t\t\t\t============================================"<<"\n";
	int pID, read ,flag, count= -1 ; 
	if(numOfMobiles()==0)
	{
		cout<<endl<<"\t\t\tCurrently "<<numOfMobiles()<<" Mobiles are present in the system!\n\n"<<endl ;
		system("Pause") ;
		admin_main() ;
	}
	
	cout<<endl<<"\nEnter student's ID: ";
	cin>>pID;
	
	try
	{
		if(pID==128) {throw 2.5 ;}
			
		if( cin.fail() ) 	{ 	throw 1 ;	}   	// if user entered anything except integers  
	
		file.open("Data.txt",ios::in) ;
		try
		{
			if(!file.is_open())  {	throw 'k' ;	}
			
			fstream f1("temp.txt",ios::out);       //Open Temporary file
			
			//================================
			//CHECK IF ID EXIST OR NOT
			ifstream iff("Data.txt",ios::in) ;
			if(!iff.is_open())  {	throw 'k' ;	}
			
			iff >> read ;
			while(iff.eof()==0)
			{
				if ( pID==read )
				{
					flag=1;
					break ;
				}
				iff >> read ;
			}
			iff.close();
			//================================
			
			while(file>>read)
			{
				count+=1 ;
				if(pID!=read)
				{
					if(count%11 == 0)
					{
						f1 << read <<" " <<endl ;
					}
					else
					{
						f1 << read <<" " ;
					}
				}
				else
				{
					file.ignore(50,'\n') ;	
					count-=1 ;
				}
			}
			file.close();
			f1.close(); 
			 
			remove("Data.txt")  ;               // Delete the original file
			rename( "temp.txt" , "Data.txt") ;  //Rename the Temporary file
			 
			if(flag!=1)
			 {
			 	cout<<endl<<"This ID does'nt exist!\n";
			 }
			 else
			 {
			 	decrement() ;               // MINUS 1 in Total number of mobiles
			 	cout<<endl<<"Record Deleted Successfully! \n";
			 }
			system("Pause") ;
		} // end inner try 
		catch(char)
		{
			cout<<"FIlE OPENING ERROR!"<<endl;
			system("pause") ;
		} // end inner catch
	
	} // end outer try
	catch(int)
	{
		invalid() ;
		deletee() ;
	}
	catch(double)
	{
		cout<<endl<<"This ID does'nt exist!\n";
		system("cls") ;
	}
}

void admin::view_all(admin *a)
{	
system("cls") ;
cout<<"\t\t\t\t============================================"<<"\n";
cout<<"\t\t\t\t\t\tDISPLAY PANEL "<<"\n";
cout<<"\t\t\t\t============================================"<<"\n";


	if(numOfMobiles()==0)
	{
		cout<<endl<<"\t\t\tCurrently "<<numOfMobiles()<<" Mobiles are present in the system!"<<endl ;
		system("Pause") ;
		admin_main() ;
	}
		displayheading() ;
		for(int i=0 ; i<numOfMobiles() ;i++)
		{
		cout<<left<<setw(5+3)<<a[i].get_ID()<<" | "<<setw(8+3)<<a[i].get_Brand()<<" | "<<setw(10+3)<<a[i].get_Purpose()<<" | ";
		cout<<setw(12+3)<<a[i].get_Processor()<<" | "<<setw(15+3)<<a[i].get_Battery_Life()<<" | "<<setw(14+3)<<a[i].get_Screen_Size()<<" | ";
		cout<<setw(10+3)<<a[i].get_Storage()<<" | "<<setw(6+3)<<a[i].get_Ram()<<" | "<<setw(9+3)<<a[i].get_Camera_Quality()<<" | "<<setw(8+3)<<a[i].get_Price()<<" | " ;
		cout<<setw(5+3)<<a[i].get_Quantity()<<" | ";
		cout<<"\n" ;
		}
		cout<<"\n" ;
		system("Pause") ;
}

void admin::search(admin *a) 
{
	system("cls") ;
	int pID ,total_Rec , check=0 ,i ;
	system("cls");	
	cout<<"\t\t\t\t============================================"<<"\n";
	cout<<"\t\t\t\t\t\tSEARCH PANEL "<<"\n";
	cout<<"\t\t\t\t============================================"<<"\n";
	
	
	
	cout<<"\n\nEnter Product-ID of the phone: " ;
	cin >> pID ;

	try
	{
		if(cin.fail()) 	{	throw 'k' ;	}
		
		total_Rec = numOfMobiles() ;   		// FIND THE TOTAL NUMBER OF MOBILES FOR LOOP

		for(i=0;i<total_Rec;i++)
		{
			if( pID==a[i].get_ID() )
			{
				check=1 ;
				break 	;
			}
		}
		try
		{
			if(check==0)  {	throw 1 ;	}
			
			a[i].Showall() ;
			system("Pause") ;
		}
		catch(int)
		{
			cout<<"This ID doesn't exist! " <<endl ; 
			cout<<"\n" ; 
			system("Pause") ;
		}
	}
	catch(...)	
	{
		cout<<"\nIn-Valid ID\nPlease enter the ID in digits"<<endl ;
		system("Pause") ;
		cin.clear() ;
		cin.ignore(1000,'\n') ;
		search(a) ;
	}
}

void admin::adminlogin()
{
    char newpass[50];
    int i = 0;
    char ch ;
    char newadmin[10] ;

	system("cls") ;
    cout<<"          --------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"          __________________________________________________________________________________________________________________________________________________\n\n";
    cout<<"                                                             ~ WELCOME TO ADMIN SIGN-IN PANEL ~                                         \n\n" ;
    cout<<"          -------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"          _________________________________________________________________________________________________________________________________________________\n\n\n";        
    
	gotoxy(60, 15);
	cout<<"\t\tM)ain Screen\t C)ontinue :\n" ;
	char u ;
	gotoxy(60, 16);
	cout<<"Choice: " ;
	cin >> u ;
	if(u=='m' || u=='M'){ MainMenu(); }
	else if(u!='m' && u!='M' && u!='c' && u!='C'){ cout<<"Invalid input\n" ; system("Pause"); adminlogin(); }
	
	
	gotoxy(60, 17);
	try
	{
		cout<<"Enter User ID : ";
    	cin.ignore();
    	cin>> newadmin ;
    	long long int match =1 ;
			for(int b=0;b<strlen(newadmin);b++)
			{									// if user entered alphabets or space=32
				if( (newadmin[b] >=97 && newadmin[b] <=122 ) || (newadmin[b] >=65 && newadmin[b] <=90 ) ) 
				{
					match++ ;
				}
				else if ( newadmin[b]==SPACE ) // if there's a Space or special char in the name
				{
					match *=100 ;  break ;
				}
			}
			if(match>=100) 
			{
				throw 2.5 ;	
			}

    	gotoxy(60, 18);
    	cout<<"Enter Password: ";

    	while(1)
    	{
        	ch = getch();
        	if(ch == ENTER)
        	{
            	newpass[i] = '\0';
            	break;
        	}
        	else if(ch == BKSP)
        	{
            	if(i > 0)
            	{
                	i--;
                	cout<<"\b \b";
            	}
        	}

        	else if(ch == TAB || ch == SPACE)
        	{
            	continue;
        	}

        	else
        	{
            	newpass[i] = ch;
            	i++;
            	cout<<"*" ;
        	}
    	}
    	if(strcmp(adminID, newadmin) == 0 && strcmp(password, newpass) == 0)  {throw 1 ;}
        else
		{
        	gotoxy(60, 22);
        	cout<<endl<<"Wrong try again !";
        	getch();
       	 	gotoxy(60, 23);
        	system("CLS");
        	adminlogin() ;
		}              
	}
    catch(float)
    {
    	cout<<"Invalid input\nUser-ID cannot have spaces and special characters!\n\n" ;
    	system("Pause") ;
    	adminlogin() ;
	}
	catch(int)
	{
		gotoxy(60, 22);
        cout<<"Successfully Log in";
        getch();
        gotoxy(60, 23);
        system("CLS");
        admin_main(); 
	}
    
    
}

void purchase_log(Mobile send_mob)
{
	customer c1 ;
	file.open("LoginData.txt",ios::in) ;
	try
	{
		if(!file.is_open()) { throw 1 ;}
		
		file.seekg( -sizeof(c1) ,ios::end);          //Move file pointer to 1 object(LAST RECORD) size from end of file
		file.read((char*)&c1 , sizeof(c1) );     	//Read the last record from file
		file.close();
		
		ofstream test1 ;
		test1.open("Purchases_Users.txt",ios::app) ;
		if(!test1.is_open()) {	throw 1 ;	}
		
		test1.write( (char*)&c1 , sizeof(c1) ) ;
		test1.close() ;
		
		ofstream test2 ;
		test2.open("Purchases_Mobile1.txt",ios::app) ;
		if(!test2.is_open()) {	throw 1 ;	}
		
		ofstream test3 ;
		test3.open("Purchases_Mobile2.txt",ios::app) ;
		if(!test3.is_open()) {	throw 1 ;	}
		
		test2 << time() ;
		test2 << send_mob.get_Brand() <<endl;
		test2 << send_mob.get_Processor()<<endl ;
		test2 << send_mob.get_Purpose() <<endl;
		
		test3 << send_mob.get_ID() <<endl ;
		test3 << send_mob.get_Battery_Life() <<endl;
		test3 << send_mob.get_Screen_Size()<<endl;
		test3 << send_mob.get_Storage() <<endl;
		test3 << send_mob.get_Ram()<<endl ;
		test3 << send_mob.get_Camera_Quality()<<endl ;
		test3 << send_mob.get_Price()<<endl ;
		test3 << send_mob.get_Quantity()<<endl ;
		test3 <<endl ;
		
		test2.close() ;
		test3.close() ;	
									
	} // end try 
	catch(int)
	{
		cout<<"\n\nFIlE OPENING ERROR!\n\n"<<endl;
		system("Pause") ;
	}
						
}






void check_out(Mobile send_mob , char *debit) //CHECK OUT ADN  BILLING
{
	cout<<"\n\t\t\tPlease wait for the confirmation of your order";
	sleep(5);
	system("cls") ;
	LoadingProcess();
	admin a;
	a.admin_helper( send_mob.get_ID() );       	//Call to deduct the quantity 
	cout<<"\n\n\n\t\t\tYour order has been confirmed. " ;
	purchase_log(send_mob) ; 
//_______________________________________________________	break the debit card number 
	char card[3] ;
	int length = strlen(debit) -1;     // XXXX-XXXX-XXXX-XXXX
	for(int i=0;i<4;i++)
	{
		card[i]=debit[length-3];
		length++;
	}
//_____________________________________________________	
	cout<<"\n\n\n\n\n\n";
	
	cout<<"\t\t\t\t_________________________________________________________________________________________________________ \n" ;
	cout<<"\t\t\t\t                                                                      							 		 \n";
	cout<<"\t\t\t\t                                                                                       		             \n";
	cout<<"\t\t\t\t                                                                                      		             \n";
	cout<<"\t\t\t\t                                                                                   					     \n";
	cout<<"\t\t\t\t            --------------------------------------------------------------------------------        		 \n";
	cout<<"\t\t\t\t              Your card XXXX-XXXX-XXXX-" <<card<< " has been charged for PKR: Rs."<<send_mob.get_Price()<<" 	 \n";
	cout<<"\t\t\t\t            ---------------------------------------------------------------------------------             \n";
	cout<<"\t\t\t\t                                                                                      					 \n";
	cout<<"\t\t\t\t                                                                                      					 \n";
	cout<<"\t\t\t\t                                                                                      					 \n";
	cout<<"\t\t\t\t                                                                                      					 \n";
	cout<<"\t\t\t\t                                Order's been placed at :"<<time()<<"              					 	 \n";
	cout<<"\t\t\t\t__________________________________________________________________________________________________________\n";
	
	cout<<"\n\n\n\n\n                                            THANK YOU !";
	
	
	cout<<"\n\nDo you wish to buy another phone?(1.Yes/2.Log-Out) " <<endl ;
	int k ;
	cout<<"\nChoice: " ;
	cin>> k ;
	if(k==1) 	{	mobileMain() ;	}
	else		{ 	MainMenu() ;	} 
	
	
		
}

void add_to_cart(Mobile send_mob)       // CART
{
	char ph ;
	int l=0 ;
	
	
		if(		send_mob.get_Quantity()==0 	) 
		{
//			cout<<""
			cout<<"This Mobile is not available at the moment\nPlease Try later!\n"<<endl;
			system("pause") ;
			mobileMain() ;
		}
		else
		{
			char choice;
			int choice1=0;
			char cvv[3];
			char address[30],debit[30],validity[30];
			cout<<"\n\t\t\t\tYou have selected this ID-->"<< send_mob.get_ID() ;
			cout<<"\n\t\t\t\tDo you want to proceed?(Y/N) : ";
			cin>>choice;
			if(choice=='y' || choice=='Y')
			{
				system("cls");         
			cout<<"\t\t\t\t============================================"<<"\n";
			cout<<"\t\t\t\t\t\t  CHECK-OUT PANEL  "<<"\n";
			cout<<"\t\t\t\t============================================"<<"\n\n\n\n";
				
				cout<<"\n\t\t\t\tPlease provide us your billing details: \n";
				while(choice1!=1)
				{
					cout<<"\t\t\t\tPlease enter your address\n";
					cin.ignore();
					cout<<"ADDRESS: " ;
					cin.getline(address,30);

					cout<<"\t\t\t\tPlease enter your Debit Card Number\n (XXXX-XXXX-XXXX-XXXX)No need to include hypens: ";
					int count=0 ;
					while(count!=19)
					{
						debit[count]=getche();
						count++;
						if(count==4 || count==9 || count==14 )
						{
							debit[count]='-';
							count++;
						}
					}
					cin.ignore();
					fflush(stdin);
					cout<<"\n\t\t\t\tWhat is the expiry date?(Validity-->MM/YY)\n";
					cin.get(validity,30);
					cin.ignore();
					cout<<"\t\t\t\tEnter your CVV Number(XXX): ";
//					cin>>cvv;
					while(l<3)
					{
						ph = getch();
	        			if(ph == ENTER)
	        			{
	            			break;
	        			}
	        			else if(ph == BKSP)
	        			{
	            			if(l > 0)
	            			{
	               	 			l--;
	               	 			cout<<"\b \b";
	           	 			}
	        			}
	        			else if(ph == TAB || ph == SPACE)
	        			{
	            			continue;
	        			}
	        			else
	        			{
	           			cvv[l] = ph;
	            		l++;
	            		cout<<ph ;
	        			}	
					}
					cout<<"\n\t\t\t\tThese are your details\n";
				
					cout<<"\n\t\t\t\t\tYour Address--> "<<address;
					cout<<"\n\t\t\t\tYour Debit Card Number--> "<<debit;
					cout<<"\n\t\t\t\tYour Expory Date--> "<<validity;
					cout<<"\n\t\t\t\tYour CVV--> "<<cvv;
				
					cout<<"\n\t\t\t\tWould you confirm these are your details?(1 for Yes/2 for No)";
					cin>>choice1;	
				}
				check_out(send_mob,debit);
			}
			else if(choice=='n'|| choice=='N'){  mobileMain();  }
		}

}
														//MAIN AND PUBLIC 
int main()
{

cout<<	time()	<<endl ;

gotoxy(65, 45) ;
cout<<"\n\n\n\n\n\n\n\n";
cout<<"\t  CCCCCC       EEEEEEEEEEE         LL               LL                  UU       UU        LL		    AAAAAAAA         RRRRRRRRR\n";
cout<<"\t CC	       EE	           LL               LL	                UU       UU        LL              AA      AA        RR      RR \n";
cout<<"\t CC            EE	           LL               LL	                UU       UU        LL              AA      AA        RR     RR\n";
cout<<"\t CC            EEEEEEE	           LL               LL	                UU       UU        LL              AAAAAAAAAA        RRRRRRRR\n";
cout<<"\t CC            EE	           LL               LL	                UU       UU        LL              AA      AA        RR     RR\n";
cout<<"\t CC            EE	           LL               LL 	                UU	 UU        LL              AA      AA        RR     RR\n";
cout<<"\t  CCCCCC        EEEEEEEEEEE	   LLLLLLLLLLL	    LLLLLLLLLLLL	UUUUUUUUUUU	   LLLLLLLLLL	   AA      AA        RR     RR\n"; 
cout<<"\t\t\t\t\t\t\t\n\n\n\n\n\n"; 
cout<<"\t\t\t\t\tTTTTTTTTTTTT         OOOOOOO         WW        WW     NNNN     NN\n";
cout<<"\t\t\t\t\t     TT             OO     OO        WW        WW     NN NN    NN\n";  
cout<<"\t\t\t\t\t     TT             OO     OO        WW        WW     NN  NN   NN\n";
cout<<"\t\t\t\t\t     TT             OO     OO        WW   WW   WW     NN   NN  NN\n";
cout<<"\t\t\t\t\t     TT             OO     OO        WW   WW   WW     NN    NN NN\n";
cout<<"\t\t\t\t\t     TT             OO     OO        WW   WW   WW     NN     NNN\n";
cout<<"\t\t\t\t\t     TT              OOOOOOO         WWWWWWWWWWWW     NN      NNN\n";

cout<<"\n\n\n\n\n\n\t\t\t\t\tEnter a key....";
getch();
system("cls");
 gotoxy(65, 40) ;
LoadingProcess();
system("cls");
MainMenu();

}

void MainMenu()  //Main sytem
{
	system("cls");
	admin a1 ;
	customer c1 ;	
	int press ;
	system("color 0A");
    cout<<"          --------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"          __________________________________________________________________________________________________________________________________________________\n\n";
    cout<<"                                                             ~ WELCOME TO MAIN SYSTEM ~                                         \n\n" ;
    cout<<"          -------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"          _________________________________________________________________________________________________________________________________________________\n\n\n";

    
    cout<<"\n\n\n";
    gotoxy(60, 8);
    ("\n\n\nPlease browse the list below and select your preferred choice\n\n\n");
    gotoxy(60, 9);
//    cout<<"1.Admin\n";
    gotoxy(60, 10);
    cout<<"2. User\n";
    gotoxy(60, 11);
    cout<<"3. Exit\n";
    gotoxy(60, 12);
    cout<<"Press : \n";
    gotoxy(70,12);
    cin >> press ;
   

    switch(press)
    {
    case 1096 :				//case 1 : if user is an admin
    case 1109 :	
    case 1106 :	
        system("CLS");
         a1.adminlogin();
    break;
	
	                
    
    case 2 :			//case 2 : if user wants to access as a user
        system("CLS");
      	c1.user_access();
    break;                
    
    case 3:				// exit 
        system("CLS");
        exit(1);
    break;               
    
    default :
    	cout<<"Invalid Input!" <<endl ;
    	cout<<"try again!"<<endl ;
    	MainMenu() ;
    
    }
    
}

void interface1(Mobile *mob , Mobile filter , int Mobsize)  //Main View
{
	string k ;
	system("cls");
	cout<<"\n\n\t\t\tWelcome to Mobile Selector\n\nChoose an option from below:";
	cout<<"\t\t\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb";
	cout<<"\n1) Show all Mobiles.\t\t\t\t\t\xba My Filter  \xba";
	cout<<"\n2) Filter Mobiles by Purpose of use.";
	cout<<"\t\t\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xbb";
	cout<<"\n3) Filter Mobiles by Brand.";
	
	// PRINT PURPOSE IN BOX
	if(filter.get_Purpose().compare(" ")==0){  cout<<"\t\t\t\xba Purpose \t\xba ANY \t  \xba" ;}
	else{ cout<<"\t\t\t\xba Purpose \t\xba"<< filter.get_Purpose() <<"\t  \xba" ; }
		
	cout<<"\n4) Filter Mobiles by Storage.";
	cout<<"\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
	cout<<"\n5) Filter Mobiles by Battery Timing.";
	
	// PRINT BRAND IN BOX
	if(filter.get_Brand().compare(" ")==0){  cout<<"\t\t\xba Brand \t\xba ANY \t  \xba" ; }
	else{ cout<<"\t\t\xba Brand \t\xba"<<filter.get_Brand()<<" \t  \xba" ; }
	
	cout<<"\n6) Filter Mobiles by Screen-Size.";
	cout<<"\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
	cout<<"\n7) Filter Mobiles by RAM.";
	
	//Print Storage in Box
	if(filter.get_Storage()==0){ cout<<"\t\t\t\xba STORAGE \t\xba ANY\t  \xba" ; }
	else{ cout<<"\t\t\t\xba STORAGE \t\xba "<<filter.get_Storage()<<"\t  \xba" ; }
	
	cout<<"\n13) Filter Mobiles by CAMERA QUALITY."; 
	cout<<"\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
	cout<<"\n14) Filter Mobiles by Processor.";
	
	//Print Battey-Life in Box
	if(filter.get_Battery_Life()==0){ cout<<"\t\t\xba Battery Life \t\xba ANY\t  \xba" ; }
	else{ cout<<"\t\t\xba Battery Life \t\xba "<<filter.get_Battery_Life()<<"\t  \xba" ; }
	
	cout<<"\n8) Clear Filter.";
	cout<<"\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n";
	cout<<"0) Logout";
	
	//Print Screen-Size in Box
	if(filter.get_Screen_Size()==0){ cout<<"\t\t\t\t\t\xba Screen-Size \t\xba ANY\t  \xba\n" ; }
	else{ cout<<"\t\t\t\t\t\xba Screen-Size \t\xba "<<filter.get_Screen_Size()<<"\t  \xba\n" ; }
	
	cout<<"\t\t\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n";

	//Print Ram in Box     \t\t\t
	if(filter.get_Ram()==0){ cout<<"\t\t\t\t\t\t\xba RAM \t\t\xba ANY\t  \xba" ; }
	else{ cout<<"\t\t\t\t\t\t\xba RAM \t\t\xba "<<filter.get_Ram()<<"\t  \xba" ; }

	cout<<"  \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n";
	
	//Print Camera in Box
	if(filter.get_Camera_Quality()==0){ cout<<"\t\t\t\t\t\t\xba Camera  \t\xba ANY\t  \xba" ; }
	else{ cout<<"\t\t\t\t\t\t\xba Camera  \t\xba"<<filter.get_Camera_Quality()<<"\t  \xba" ; }
	
	cout<<"  \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n";
	
	//Print Processor in Box
	if(filter.get_Processor().compare(" ")==0){ cout<<"\t\t\t\t\t\t\xba Processor \t\xba ANY\t  \xba" ; }
	else{ cout<<" \t\t\t\t\t\t\t\t\t\xba Processor \t\xba"<<filter.get_Processor()<<"\t  \xba" ; }
	
	cout<<"  \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n";
	//Print Count of Mobiles
	cout<<"\t\t\t\t\t\t\xba Total \t\xba "<<filter.getFilteredMobiles(mob,filter,Mobsize) <<"\t  \xba" ;
	cout<<"  \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n";
}

void interface2(Mobile* mob,int count){      //MOBILE INFO!
	Mobile send_mob ;
	int i ;
	int choice=0 ,select;
	if(count==2)
	{
		cout<<"\n\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb";
		cout<<"\n\xba ID:\t\t\xba "<<mob[0].get_ID()<<"      \t\xba " << mob[1].get_ID() <<"      \t     \xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba PURPOSE:\t\xba "<<mob[0].get_Purpose()<<" \t\t\xba "<<mob[1].get_Purpose()<<" \t\t     \xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba BRAND:\t\xba "<<mob[0].get_Brand()<<"\"\t\xba "<<mob[1].get_Brand()<<"\"\t     \xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba SCREEN SIZE:\t\xba "<<mob[0].get_Screen_Size()<<"\"\t\t\xba "<<mob[1].get_Screen_Size()<<"\"\t\t     \xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba PROCESSOR:\t\xba " << mob[0].get_Processor() << "  \t\xba " << mob[1].get_Processor() << "  \t     \xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba STORAGE:\t\xba "<<mob[0].get_Storage()<<" GB\t\t\xba "<<mob[1].get_Storage()<<" GB\t\t     \xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba RAM:\t\t\xba "<<mob[0].get_Ram()<<" GB\t\t\xba "<<mob[1].get_Ram()<<" GB\t\t     \xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba CAMERA :\t\xba "<<mob[0].get_Camera_Quality()<<"\t\t\xba "<<mob[1].get_Camera_Quality()<<"\t\t     \xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba BATTERY LIFE:\t\xba "<<mob[0].get_Battery_Life()<<" hrs  \t\xba "<<mob[1].get_Battery_Life()<<" hrs  \t     \xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba PRICE:\t\xba Rs."<<mob[0].get_Price()<<"/-\t\xba Rs."<<mob[1].get_Price()<<"/-\t     \xba";
		cout<<"\n\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
		
		
		cout<<"Do you wish to buy a phone from us?(1.Yes/2.No) " ;
		cin>> select ;
		if(select==1)
		{
			cout<<"\nWhich Phone do you want to purchase.Enter Its ID:";
			cin>>choice;
			for(i=0;i<2;i++)
			{
				if(choice==mob[i].get_ID())
				{
					send_mob= mob[i] ;      //operator overloading
					break;
				}
			}
			add_to_cart(send_mob);
		}
		else
		{
			mobileMain() ;
		}
	}
	
	else if( count==3 )
	{

		cout<<"\n\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb";
		cout<<"\n\xba ID:\t\t\xba "<<mob[0].get_ID()<<"      \t\xba "<<mob[1].get_ID()<<"      \t\xba "<<mob[2].get_ID()<<"      \t\xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba BRAND:\t\xba "<<mob[0].get_Brand()<<"\t\xba "<<mob[1].get_Brand()<<"\t\xba "<<mob[2].get_Brand()<<" \t\xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba SCREEN SIZE:\t\xba "<<mob[0].get_Screen_Size()<<"\t\t\xba "<<mob[1].get_Screen_Size()<<"\t\t\xba "<<mob[2].get_Screen_Size()<<"\t\t\xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba PROCESSOR:\t\xba "<<mob[0].get_Processor()<<"  \t\xba "<<mob[1].get_Processor()<<"  \t\xba "<<mob[2].get_Processor()<<"  \t\xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba STORAGE:\t\xba "<<mob[0].get_Storage()<<"\t  GB\t\xba "<<mob[1].get_Storage()<<" GB\t\t\xba "<<mob[2].get_Storage()<<" GB\t\xba";
		
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba PURPOSE:\t\xba "<<mob[0].get_Purpose()<<"\t  \t\xba "<<mob[1].get_Purpose()<<" \t\t\xba "<<mob[2].get_Purpose()<<" \t\t\xba";
		
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba RAM:\t\t\xba "<<mob[0].get_Ram()<<" GB\t\t\xba "<<mob[1].get_Ram()<<" GB\t\t\xba "<<mob[2].get_Ram()<<" GB\t\t\xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba CAMERA:\t\xba "<<mob[0].get_Camera_Quality()<<"\t\t\xba "<<mob[1].get_Camera_Quality()<<"\t\t\xba "<<mob[2].get_Camera_Quality()<<"\t\t\xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba BATTERY LIFE:\t\xba "<<mob[0].get_Battery_Life()<<" hrs  \t\xba "<<mob[1].get_Battery_Life()<<" hrs  \t\xba "<<mob[2].get_Battery_Life()<<" hrs  \t\xba";
		cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
		cout<<"\n\xba PRICE:\t\xba  "<<mob[0].get_Price()<<"\t\xba  "<<mob[1].get_Price()<<"\t\xba  "<<mob[2].get_Price()<<" \t\xba";
		cout<<"\n\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
		
		cout<<"Do you wish to buy a phone from us?(1.Yes/2.No) " ;
		cin>> select ;
		if(select==1)
		{
			cout<<"\nWhich Phone do you want to purchase.Enter Its ID:";
			cin>>choice;
			for(i=0;i<2;i++)
			{
				if(choice==mob[i].get_ID())
				{
					send_mob= mob[i] ;      //operator overloading
					break;
				}
			}
			add_to_cart(send_mob);
		}
		else
		{
			mobileMain() ;
		}
		
	} 
	else if (count > 3 )
	{
		int sneak ;
		cout<<endl<<"COUNT"<<count<<endl ;
		count=count-1;
		sneak = count ;
		for( count ; count>=0; count-- ) 
		{
			cout<<"\n\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb";
			cout<<"\n\xba ID:\t\t\xba"<<mob[count].get_ID() <<"\t\t\xba" ; 
			cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
			cout<<"\n\xba PURPOSE:\t\xba"<<mob[count].get_Purpose()<<"\t\t\xba" ;
			
			cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
			cout<<"\n\xba BRAND:\t\xba"<<mob[count].get_Brand()<<"\t\t\xba" ;
			
			cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
			cout<<"\n\xba SCREEN SIZE:\t\xba"<<mob[count].get_Screen_Size()<<"\"\t\t\xba" ;
			cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
			cout<<"\n\xba PROCESSOR:\t\xba"<<mob[count].get_Processor()<<"\t\xba" ;
			cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
			cout<<"\n\xba STORAGE:\t\xba"<<mob[count].get_Storage()<<" GB\t\t\xba" ;
			cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
			cout<<"\n\xba RAM:\t\t\xba"<<mob[count].get_Ram()<<" GB\t\t\xba" ;
			cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
			cout<<"\n\xba CAMERA:\t\xba "<<mob[count].get_Camera_Quality()<<" MP \t\xba " ;
			cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
			cout<<"\n\xba BATTERY LIFE:\t\xba"<<mob[count].get_Battery_Life()<<" hrs \t\xba" ;
			cout<<"\n\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9";
			cout<<"\n\xba PRICE:\t\xba Rs."<<mob[count].get_Price()<<" /-\t\xba" ;
			cout<<"\n\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc";
			cout<<"\n\n\n"<<count<<endl ;
//				
		} //end for
		cout<<"Do you wish to buy a phone from us?(1.Yes/2.No) " ;
		cin>> select ;
		if(select==1)
		{
			cout<<"\nWhich Phone do you want to purchase.Enter Its ID:";
			cin>>choice;
			for(sneak ; sneak>=0 ; sneak--)
			{
				if(choice==mob[sneak].get_ID())
				{
					send_mob = mob[sneak] ;      //operator overloading
					break;
				}
			}
			add_to_cart( send_mob );
		}
		else
		{
			mobileMain() ;
		}
	}
}

void displayheading()						//the heading bar for interface2().It contains Built-in Functions of <iomanip>
{
cout<<"\n\n\n" ;

cout<<"  ID"<<"\t   BRAND"<<"\t   PURPOSE"<<"\t   PROCESSOR"<<"\t     BATTERY-LIFE"<<"\t   SCREEN SIZE"<<"       STORAGE"<<"\t     RAM"<<"\t  CAMERA"<<"\t  PRICE"<<"\t     QUANTITY\n";


cout<<"=======================================================================================================================================================================\n";
}

long int fileSize()   						//DETERMINE THE SIZE OF THE FILE
{
	file.open("Data.txt", ios::in);
	try
	{
		if(!file.is_open())
		{
			throw 'k' ;
		}
		file.seekg(0,ios::end);
		
		long int size=file.tellg();
		file.close();
		return size;	
	}
	catch(...)
	{
		cout<<"\nFIlE OPENING ERROR!"<<endl;
		system("Pause") ;
	}
}

int numOfMobiles()  						//Display number of records
{
	if( fileSize()==0 )   	// If file is empty
	{
		return 0 ;
	}
	int count=1 ;
	file.open("Data.txt", ios::in);
	
	try
	{
		if(!file.is_open())			{		throw 'k'; 		}
		
		file.seekg(0) ;
		count= nextValue(file) ;
		file.close();
		return (count) ;	
	}
	catch(...)
	{
		cout<<"FIlE OPENING ERROR!\n"<<endl;
		system("pause");
		return  0 ;
	}
}

string time()     // To determine the current time/date from the system
{               
	// Declaring argument for time() 
	time_t tt ; 
	
	char *s ;

	// Declaring variable to store return value of 
	// localtime() 
	struct tm * ti; 

	// Applying time() 
	time (&tt); 

	// Using localtime() 
	ti = localtime(&tt); 
	
	s= asctime(ti) ;
	return s ;
	cout<<s<<endl ;
	
}


