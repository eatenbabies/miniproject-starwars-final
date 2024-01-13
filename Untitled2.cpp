//Kiana Jaberi 40212358013
//Niki Mahmoudi 
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std ;

struct location {
	int loc1 ;
	int loc2 ;
};
bool end_of_the_table ( char , location ) ;
bool wrong_input1 ( char ) ;
bool wrong_input2 ( char ) ;
bool wrong_input3 ( char ) ;

int main (){
	
	char spaceships [10][10] ;
	location f_loc ;
	location s_loc ;
	int lives = 3 ;
	char action ;
	char move ;
	char shoot ;
	int enemy_spaceships = 10 ;
	
	srand ( time ( 0 ) ) ;
	for ( int i = 0 ; i < 11 ; i ++ ){
		
		int rand1 = rand () % 10 ;
		int rand2 = rand () % 10 ;
		
		if ( spaceships [rand1][rand2] == '*' )
			i -- ;
		else if ( spaceships [rand1][rand2] == 'O' )
		    i -- ;
		    
		if ( i == 10 ){
			if ( spaceships [rand1][rand2] == '*' )
			    i -- ;
			else {
		    	spaceships [rand1][rand2] = 'O' ;
		    	f_loc.loc1 = rand1 ;
		    	f_loc.loc2 = rand2 ;
		    	s_loc.loc1 = rand1 ;
		    	s_loc.loc2 = rand2 ;
		    }
		}
		else 
		    spaceships [rand1][rand2] = '*' ;
	}
	
	while ( lives != 0 ){
		
		cout << "###### StarWars ######" << endl << endl ;
		cout << "Lives : " << lives << endl ;
		
		for ( int i = 0 ; i < 10 ; i ++ ){
			
			for ( int j = 0 ; j < 10 ; j ++ )
			    cout << " ---" ;
			cout << endl ;
			
			for ( int k = 0 ; k < 10 ; k ++ ){
				cout << "| " ;
				if ( spaceships [i][k] == 'O' )
				    cout << "O " ;
				else if ( spaceships [i][k] == '*' )
				    cout << "* " ;
				else
				    cout << "  " ;
			}
			cout << "|" << endl ;
		}
		for ( int i = 0 ; i < 10 ; i ++ )
		    cout << " ---" ;
		cout << endl << endl ;
		
		while ( true ){
			
	    	cout << "Move (M) or Shoot (S) ?" << endl ;
		    action = getch () ;
		    
		    bool input = wrong_input1 ( action ) ;
		    if ( input == false ){
	    	    cout << "Error!" << endl ;
	    	    continue ;
	    	}
    	    break ;
        }
        
        if ( action == 'M' ){
        	
        	while ( true ){
				
		    	cout << "Up (U) , Down (D) , Right (R) , Left (L)" << endl ;
		    	move = getch () ;
		    	
		    	bool input = wrong_input2 ( move ) ;
				if ( input == false ){
					cout << "Error!" << endl ;
					continue ;
				}
						    	            
		    	bool flag = end_of_the_table ( move , s_loc ) ;
		    	if ( flag == false ){
		    		cout << "Error!" << endl ;
		    	    continue ;
				}
		    	break ;
		    }
		    
		   spaceships [s_loc.loc1][s_loc.loc2] = ' ' ;
		   
		   if ( move == 'U' ){
		    	if ( spaceships [s_loc.loc1 - 1][s_loc.loc2] == '*' ){
					spaceships [f_loc.loc1][f_loc.loc2] = 'O' ;
					s_loc.loc1 = f_loc.loc1 ;
					s_loc.loc2 = f_loc.loc2 ;
					lives -- ;
				}
				else {
					spaceships [s_loc.loc1 - 1][s_loc.loc2] = 'O' ;
					s_loc.loc1 -- ;
				}
			}
			
			if ( move == 'D' ){
		    	if ( spaceships [s_loc.loc1 + 1][s_loc.loc2] == '*' ){
					spaceships [f_loc.loc1][f_loc.loc2] = 'O' ;
					s_loc.loc1 = f_loc.loc1 ;
					s_loc.loc2 = f_loc.loc2 ;
					lives -- ;
				}
				else {
					spaceships [s_loc.loc1 + 1][s_loc.loc2] = 'O' ;
					s_loc.loc1 ++ ;
				}
			}
			
			if ( move == 'R' ){
		    	if ( spaceships [s_loc.loc1][s_loc.loc2 + 1] == '*' ){
					spaceships [f_loc.loc1][f_loc.loc2] = 'O' ;
					s_loc.loc1 = f_loc.loc1 ;
					s_loc.loc2 = f_loc.loc2 ;
					lives -- ;
				}
				else {
					spaceships [s_loc.loc1][s_loc.loc2 + 1] = 'O' ;
					s_loc.loc2 ++ ;
				}
			}
			
			if ( move == 'L' ){
		    	if ( spaceships [s_loc.loc1][s_loc.loc2 - 1] == '*' ){
					spaceships [f_loc.loc1][f_loc.loc2] = 'O' ;
					s_loc.loc1 = f_loc.loc1 ;
					s_loc.loc2 = f_loc.loc2 ;
					lives -- ;
				}
				else {
					spaceships [s_loc.loc1][s_loc.loc2 - 1] = 'O' ;
					s_loc.loc2 -- ;
				}
			}
			
			system (" cls ") ;
		}
		
		if ( action == 'S' ){
			
			while ( true ){
		    	cout << "Right (R) , Left (L)" << endl ;
		    	shoot = getch () ;
		    	
		    	bool input = wrong_input3 ( shoot ) ;
		    	if ( input == false ){
		    		cout << "Error!" << endl ;
		    		continue ;
				}
		    	break ;
			}
			
		    int i = 1 ;
			if ( shoot == 'R' ){
				while ( i != 0 ){
					if ( spaceships [s_loc.loc1][s_loc.loc2 + i] == '*' ){
						spaceships [s_loc.loc1][s_loc.loc2 + i] = ' ' ;
						i = 0 ;
						enemy_spaceships -- ;
					}
					else
					    i ++ ;
				}
			}
			i = 1 ;
			if ( shoot == 'L' ){
				while ( i != 0 ){
					if ( spaceships [s_loc.loc1][s_loc.loc2 - i] == '*' ){
						spaceships [s_loc.loc1][s_loc.loc2 - i] = ' ' ;
						i = 0 ;
						enemy_spaceships -- ;
					}
					else
					    i ++ ;
				}
			}
			
			system (" cls ") ;
			
			if ( enemy_spaceships == 0 ){
				cout << "you win :)" << endl ;
				break ;
			}
		}
	}
	if ( enemy_spaceships != 0 ){
		cout << "game over :|" ;
	}
	
	return 0 ;
}

bool end_of_the_table ( char move , location s_loc ){
	
	bool flag = true ;
	
	if ( move == 'U' )
	    if ( s_loc.loc1 == 0 )
	        flag = false ;
	        
	if ( move == 'D' )
	    if ( s_loc.loc1 == 9 )
	        flag = false ;
	        
	if ( move == 'R' )
	    if ( s_loc.loc2 == 9 )
	        flag = false ;
	        
	if ( move == 'L' )
	    if ( s_loc.loc2 == 0 )
	        flag = false ;
	
	return flag ;
}

bool wrong_input1 ( char action ){
	
	bool input = true ;
	
	if ( action != 'M' )
	    if ( action != 'S' )
    		input = false ;
    	
	return input ;
}

bool wrong_input2 ( char move ){
	
	bool input = true ;
	
	if ( move != 'U' )
        if ( move != 'D' )
		    if ( move != 'R' )
		    	if ( move != 'L' )
		    	    input = false ;
	
	return input ;
}

bool wrong_input3 ( char shoot ){
	
	bool input = true ;
	
	if ( shoot != 'R' )
		if ( shoot != 'L' )
		    input = false ;
	
	return input ;
}