//playground with sleep
#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std ;

int main (){

	int i , j , k ;
	char array [10][10] ;
	int random1 , random2 ;
	char array2 [1][1] ;

    for ( i = 0 ; i < 11 ; i ++ ){
       	srand (time(0)) ;
       	random1 = rand () % 10 ;
       	random2 = rand () % 10 ;
       	if ( i == 10 ){
       		array [random1][random2] = 'O' ;
       	}
       	else {
       	    array [random1][random2] = '*' ;
       	}
       	sleep ( 1 ) ;
    }
    
	for ( i = 0 ; i < 10 ; i ++ ){
		for ( j = 0 ; j < 10 ; j ++ ){
			cout << " ---" ;
		}
		cout << endl ;
		for ( k = 0 ; k < 10 ; k ++ ){
			cout << "| " ;
			array [i][k] ;
			
			if ( array [i][k] == 'O' ){
				cout << "O " ;
			}
			else if ( array [i][k] == '*' ){
				cout << "* " ;
			}
			else {
				cout << "  " ;
			}
		}
		cout << "|" ;
		cout << endl ;
	}
	for ( j = 0 ; j < 10 ; j ++ ){
			cout << " ---" ;
		}
		
	return 0 ;
}