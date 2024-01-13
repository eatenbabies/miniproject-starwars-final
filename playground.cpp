#include <iostream>
using namespace std ;

int main (){

	int i , j , k , a ;
	
	for ( i = 0 ; i < 10 ; i ++ ){
		for ( j = 0 ; j < 10 ; j ++ ){
			cout << " ---" ;
		}
		cout << endl ;
		for ( k = 0 ; k < 11 ; k ++ ){
			cout << "|   " ;
		}
		cout << endl ;
	}
	for ( int j = 0 ; j < 10 ; j ++ ){
			cout << " ---" ;
		}
		
	return 0 ;
}