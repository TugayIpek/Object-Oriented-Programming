#include "AbstractBoard.h"
namespace Tugay{
	bool AbstractBoard::operator==(AbstractBoard &obj){
		if(column != obj.column || row != obj.row) return false;
		else{
		    for( int i = 0 ; i < column ; ++i ){
		        for( int k = 0 ; k < row ; ++k ){
		           if( operator()(i,k) != obj.operator()(i,k) )
		                return false;
		        }
		    }  
	  	}
	    return true;
	}
}