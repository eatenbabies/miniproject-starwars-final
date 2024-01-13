#include <iostream>
#include <time.h>
using namespace std ;

int main (){
	
	char playground [10][10] ;
	int rand1 , rand2 ;
	
	//srand (time(0)) ;
	for ( int i = 0 ; i < 10 ; i ++ ){
		int rand1 = rand () % 10 ;
		int rand2 = rand () % 10 ;
		if ( playground [rand1][rand2] == '*' )
			i -- ;
		else 
			playground [rand1][rand2] = '*' ;
	}
	
	int rand11 , rand22 ;
	
	for ( int i = 0 ; i < 1 ; i ++ ){
		int rand1 = rand () % 10 ;
		int rand2 = rand () % 10 ;
		if ( playground [rand1][rand2] == '*' )
			i -- ;
		else {
			playground [rand1][rand2] = 'O' ;
			rand11 = rand1 ;
			rand22 = rand2 ;
		}
	}
	
	for ( int i = 0 ; i < 10 ; i ++ ){
		for ( int j = 0 ; j < 10 ; j ++ )
			cout << " ---" ;
		cout << endl ;
		for ( int k = 0 ; k < 10 ; k ++ ){
			cout << "| " ;
			playground [i][k] ;
			if ( playground [i][k] == '*' )
				cout << "* " ;
			else if ( playground [i][k] == 'O' )
				cout << "O " ;
			else 
				cout << "  " ;
		}
		cout << "|" << endl ;
	}
	for ( int j = 0 ; j < 10 ; j ++ )
			cout << " ---" ;
	return 0 ;
}