#include <iostream>
#include <ctime> //srand function
#include <conio.h> //getch function
using namespace std ;

bool wrong_move ( char , int , int ) ; //move to the end of the table

int main (){
	
	char spaceships [10][10] ; //position of spaceships
	int loc1 , loc2 ; //the changing position of our spaceship
	int loc11 , loc22 ; //save the first position of our spaceship
	char action ; //move or shoot
	char move ; //move
	char shoot ; //shoot
	int counter = 10 ; //counting the number of enemy spaceships
	int heal = 3 ; //number of lives
	
	srand ( time ( 0 ) ) ;
	for ( int i = 0 ; i < 11 ; i ++ ){ //determining the position of spaceships
		
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
		    	loc1 = rand1 ;
		    	loc2 = rand2 ;
		    	loc11 = rand1 ;
		    	loc22 = rand2 ;
		    }
		}
		else 
		    spaceships [rand1][rand2] = '*' ;	    
	}
	
	while ( heal != 0 ){ 
		
		cout << "heal : " << heal << endl << endl ;
		
		for ( int i = 0 ; i < 10 ; i ++ ){ //playground printing
			
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
		
		while ( true ){ //receive action
		
	    	cout << "move (M) or shoot (S) ?" << endl ;
		    action = getch () ; //cin >> action
		
	    	if ( action != 'M' )
	    	    if ( action != 'S' ){
    		        cout << "Error!" << endl ;
    		        continue ;
    	    	}
    	    break ;
    	}
		
		if ( action == 'M' ){ //move
			
			while ( true ){ //move toward
				
		    	cout << "Up (U) , Down (D) , Right (R) , Left (L)" << endl ;
		    	move = getch() ; //cin >> move
		    	
		    	if ( move != 'U' )
		    	    if ( move != 'D' )
		    	        if ( move != 'R' )
		    	            if ( move != 'L' ){
		    	                cout << "Error!" << endl ;
		    	                continue ;
		    	            }
		    	            
		    	bool flag = wrong_move ( move , loc1 , loc2 ) ; //move to the end of the table
		    	if ( flag == false ){
		    		cout << "Error!" << endl ;
		    	    continue ;
				}
				
		    	break ;
		    }
		    
		    spaceships [loc1][loc2] = '  ' ;
		    
		    if ( move == 'U' ){ //move up
		    	if ( spaceships [loc1 - 1][loc2] == '*' ){
		    		heal -- ;
					spaceships [loc11][loc22] = 'O' ;
					loc1 = loc11 ;
					loc2 = loc22 ;
				}
				else {
					spaceships [loc1 - 1][loc2] = 'O' ;
					loc1 -- ;
				}
			}
			
			if ( move == 'D' ){ //move down
		    	if ( spaceships [loc1 + 1][loc2] == '*' ){
		    		heal -- ;
					spaceships [loc11][loc22] = 'O' ;
					loc1 = loc11 ;
					loc2 = loc22 ;
				}
				else {
					spaceships [loc1 + 1][loc2] = 'O' ;
					loc1 ++ ;
				}
			}
			
			if ( move == 'R' ){ //move right
		    	if ( spaceships [loc1][loc2 + 1] == '*' ){
		    		heal -- ;
					spaceships [loc11][loc22] = 'O' ;
					loc1 = loc11 ;
					loc2 = loc22 ;
				}
				else {
					spaceships [loc1][loc2 + 1] = 'O' ;
					loc2 ++ ;
				}
			}
			
			if ( move == 'L' ){ //move left
		    	if ( spaceships [loc1][loc2 - 1] == '*' ){
		    		heal -- ;
					spaceships [loc11][loc22] = 'O' ;
					loc1 = loc11 ;
					loc2 = loc22 ;
				}
				else {
					spaceships [loc1][loc2 - 1] = 'O' ;
					loc2 -- ;
				}
			}
			
			system (" cls ") ;
		}
		
		if ( action == 'S' ){ //shoot
			
			while ( true ){ //shoot toward
		    	cout << "Right (R) , Left (L)" << endl ;
		    	shoot = getch () ; //cin >> shoot
		    	if ( shoot != 'R' )
		    	    if ( shoot != 'L' ){
		    	        cout << "Error!" << endl ;
		    	        continue ;
		    	    }
		    	break ;
			}
			
			if ( shoot == 'R' ){ //shoot right
				if ( spaceships [loc1][loc2 + 1] == '*' ){
					spaceships [loc1][loc2 + 1] = ' ' ;
					counter -- ;
				}
			}
			
			if ( shoot == 'L' ){ //shoot left
				if ( spaceships [loc1][loc2 - 1] == '*' ){
					spaceships [loc1][loc2 - 1] = ' ' ;
					counter -- ;
				}
			}
			
			system (" cls ") ;
			
			if ( counter == 0 ){
				cout << "you win :)" << endl ;
				break ;
			}
		}
	}
	
	if ( counter != 0 ){
		cout << "game over :|" ;
	}
	
	return 0 ;
}

bool wrong_move ( char move , int loc1 , int loc2 ){ //move to the end of the table
	
	bool flag = true ;
	
	if ( move == 'U' )
	    if ( loc1 == 0 )
	        flag = false ;
	        
	if ( move == 'D' )
	    if ( loc1 == 9 )
	        flag = false ;
	        
	if ( move == 'R' )
	    if ( loc2 == 9 )
	        flag = false ;
	        
	if ( move == 'L' )
	    if ( loc2 == 0 )
	        flag = false ;
	
	return flag ;
}