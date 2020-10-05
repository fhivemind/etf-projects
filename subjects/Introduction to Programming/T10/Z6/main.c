#include <stdio.h>


/* remove comments function */
char* ukloni_komentare(char* text) {
   /* initial */
   char *edit = text;
   char *poc = text;
   char *output = edit;
   int _set = 0, _validity = 0;
   
   while(*text != '\0') {
       
       /* find comment text */
        _set = 0;
        if(_validity) 
            _set = (*(text-1) =='/' && *text == '/');
        
        /* find C++ comment */
        if((*text == '/' && *(text+1) == '/') || _set) {
            if(_set)
                text--;
                
            poc = text;
            edit = text;
           
            while(*text != '\n') {
               if(*text != '\0') text++;
               else break;
            }
           
            while((*edit++ = *text++));
           
            text = poc;
            edit = poc;

        }
        /* find C comment */
        else if(*text == '/' && *(text+1) == '*') {
            
            poc = text;
            edit = text;
            
            if(*text != '\0') text++;
            if(*text != '\0') text++;
            
            _set = 0;
            while(!(*text == '*' && *(text+1) == '/')) {
                if(*text != '\0')
                    text++;
                else {
                   _set = 1;
                   break;
               }
            }
            
            if(*text != '\0') text++;
            if(*text != '\0') text++;
            
            if(!_set) 
                while((*edit++ = *text++));
                
            text = poc;
            edit = poc;
        }
        text++;
        _validity = 1;
      
   }
   return output;
}


int main() {
	return 0;
}