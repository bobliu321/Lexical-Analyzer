//Use only the following three libraries:
#include "parserClasses.h"
#include <iostream>
#include <fstream>

using namespace std;

//Example Test code for interacting with your Token, TokenList, and Tokenizer classes
//Add your own code to further test the operation of your Token, TokenList, and Tokenizer classes
int main() {
        ifstream sourceFile;
        TokenList tokens;

  //Lists for types of tokens
  TokenList operatorTokens;
  TokenList identifierTokens;
  TokenList literalTokens;
  TokenList commentBodyTokens;
  TokenList otherTokens;

        Tokenizer tokenizer;
        //Read in a file line-by-line and tokenize each line
        vector <int> filler = {};
        vector <string> printLine={};
        sourceFile.open("Imsad.vhd");
        if (!sourceFile.is_open()) {
                cout << "Failed to open file" << endl;
                return 1;
        }

        while(!sourceFile.eof()) {
                string line;
                getline(sourceFile, line);
        printLine.push_back(line);
                tokenizer.setString(&line);

                 //int myLine = tokenizer.Getline();
                // cout<<myLine <<endl;
                while(!tokenizer.isComplete()) {
            //    cout<<"hell";
                        tokens.append(tokenizer.getNextToken());
                          filler.push_back( tokenizer.Getline()) ;

                }
        }


        /*Test your tokenization of the file by traversing the tokens list and printing out the tokens*/
        //removeComments(tokens);

          /*Test your tokenization of the file by traversing the tokens list and printing out the tokens*/
          ////////ORIGINAL////////////////////////////////////////////////////////////////////////////////////////
       Token *t = tokens.getFirst();
         cout<<"orignal list"<<endl;
        while(t) {

                cout << t->getStringRep() << " ";
               // tokens.findAndSetTokenDetails(t);
     // tokens.findAndSetTokenDetails(t);
                t = t->getNext();
        }
       // removeTokensOfType(tokens, T_CommentBody);

////////////////////////PART1TESTING///////////////////////////////////////////////////////////////////////////////////
//        Token *t = tokens.getFirst();
 //      Token *t = tokens.getFirst();
//        Token *t = tokens.getFirst();
        TokenList Copy(tokens); // Using copy contructor
        t = Copy.getFirst();
         cout<<"copied list"<<endl;
        while(t) {

                cout << t->getStringRep() << " ";
                tokens.findAndSetTokenDetails(t);
                t = t->getNext();

        }
      /*  removeTokensOfType(Copy, T_CommentBody);
        cout<<endl;
        t = Copy.getFirst();
        while(t) {

                cout << t->getStringRep() << " ";
                t = t->getNext();
        }*/

        cout<<endl<<endl;

        t = Copy.getFirst();
        while(t)
        {
            if(t->isOperator()) // if it is an operator
            {operatorTokens.append(t->getStringRep());} //append to operator tokens list

            else if(t->isComment())// if it is an comment
            { commentBodyTokens.append(t->getStringRep());}//append to comment body tokens list

            else if(t->isOther())// if it is an other
            {otherTokens.append(t->getStringRep());}//append to other body tokens list

            else if(t->isLiteral())// if it is an literal
            {literalTokens.append(t->getStringRep());}

            else if(t->isIdentifier())// if it is an identifier
            {identifierTokens.append(t->getStringRep());}//append to identifier body tokens list

            cout<<t->getStringRep()<<" type: "<< t->getTokenType()<<" keyword: "<<t->isKeyword();
            if(t->getTokenDetails()) // if it has test
            {
                  cout <<" string type: "<< t->getTokenDetails()->type<< " the width is: " << t->getTokenDetails()-> width <<endl; // if details give type and width
            }

            else
            {
                cout << endl;
            }

            t = t->getNext(); // iterates through
       }
       //////////////////////////////PART2TESTING//////////////////////////////////////////////////////////////////////////////////////////////
        cout<<"My conditional statements are: ";
        //Token *cursor = operatorTokens.getFirst();
        Token *stuff=findAllConditionalExpressions(Copy)->getFirst();
        while(stuff)
        {
            cout << stuff->getStringRep() << " ";
                stuff= stuff->getNext();
        }
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;

       t = tokens.getFirst();
         cout<<"orignal list"<<endl;
        while(t) {

                cout << t->getStringRep() << " ";
               // tokens.findAndSetTokenDetails(t);
     // tokens.findAndSetTokenDetails(t);
                t = t->getNext();
        }
       // removeTokensOfType(tokens, T_CommentBody);


        string mode;
        cout<<endl;
        cout<< "Do you want verbose or non-verbose mode or BONUS!?: " << endl;
        cin >> mode;

       /////////////////////////////NON VERBOSE MODE TESTING//////////////////////////////////////////////////////
       if( LowerString(mode) == "non-verbose")
       {

        cout<<endl<<endl;
        t = Copy.getFirst();
        cout << "THE TOTAL AMOUNT OF TOKENS IN THIS VHDL IS : " << TokensCounter(Copy) << endl; //Part A
        int missingThen;
        int missingEnd;
        int CondExp;
        CompletePairing(Copy,missingThen,missingEnd,CondExp); //call by reference
        cout<<"TOTAL NUMBER OF MISSING THENS: "<<missingThen<<endl;
        cout<<"TOTAL NUMBER OF MISSING END IFS: "<<missingEnd<<endl;
         cout<<"TOTAL NUMBER OF CONDITIONAL EXPRESSIONS: "<<CondExp<<endl;

        //removeComments(tokens);
        int noMisMatch = 0; // declaring variable for call by ref call
        int TypeMatchNotWidth = 0;
        int WidthMatchNotType = 0;
        int NoWidthNoType = 0;

        TypeMatch(Copy,noMisMatch, TypeMatchNotWidth, WidthMatchNotType, NoWidthNoType);
            cout << "MATCH NO ERROR " << " " << noMisMatch<<endl;
           cout <<"TYPE MATCHES BUT WIDTH DOES NOT ERROR"<<" " << TypeMatchNotWidth<<endl;
            cout <<"WIDTH MATCHES BUT TYPE DOES NOT ERROR"<<" " << WidthMatchNotType << endl;
            cout << "WIDTH AND TYPE BOTH DO NOT MATCH ERROR"<<" " << NoWidthNoType << endl;


       }



////////////////////////////////////VERBOSE TESTING///////////////////////////////////////////////////////////////////////
if( LowerString(mode) == "verbose")
{
      cout<<endl<<endl;
        t = Copy.getFirst();
        cout << "THE TOTAL AMOUNT OF TOKENS IN THIS VHDL IS : " << TokensCounter(Copy) << endl; //Part A
        int missingThen;
        int missingEnd;
        int CondExp;
        CompletePairing(Copy,missingThen,missingEnd,CondExp);
        cout<<"TOTAL NUMBER OF MISSING THENS: "<<missingThen<<endl;
        cout<<"TOTAL NUMBER OF MISSING END IFS: "<<missingEnd<<endl;
       //  cout<<"TOTAL NUMBER OF CONDITIONAL EXPRESSIONS: "<<CondExp<<endl;

        //removeComments(tokens);
        int noMisMatch = 0;
        int TypeMatchNotWidth = 0;
        int WidthMatchNotType = 0;
        int NoWidthNoType = 0;

        TypeMatch(Copy,noMisMatch, TypeMatchNotWidth, WidthMatchNotType, NoWidthNoType);
            cout << "MATCH NO ERROR " << " " << noMisMatch<<endl;
           cout <<"TYPE MATCHES BUT WIDTH DOES NOT ERROR"<<" " << TypeMatchNotWidth<<endl;
            cout <<"WIDTH MATCHES BUT TYPE DOES NOT ERROR"<<" " << WidthMatchNotType << endl;
            cout << "WIDTH AND TYPE BOTH DO NOT MATCH ERROR"<<" " << NoWidthNoType << endl;







    CompletePairing(Copy,missingThen,missingEnd,CondExp);
t=Copy.getFirst();
unsigned i=0;
vector <int> errorlines = {};

while(t)
    {
        if(i<filler.size())
        {
                        t->numLineofToken.push_back(filler[i]); //transferring a vector into another vector to be used in this scope
                        t=t->getNext();
                        i++;
        }
    }


unsigned int ii=0;
  int errorline=0; // which line has error it holds
  t=Copy.getFirst(); // starts at first token
  int preverrorline=0; // line in which previous error is on
  bool error1=false; // type match width does not
  bool error2=false; // width match typ does not
  bool error3=false; // type and width both don't match
  bool noerror=true;
 noMisMatch = 0;
TypeMatchNotWidth = 0;
WidthMatchNotType = 0;
NoWidthNoType = 0;

        TypeMatch(Copy,noMisMatch, TypeMatchNotWidth, WidthMatchNotType, NoWidthNoType);
while(t)
{
  if(errorline!=0 && errorline!=preverrorline) // if currrent line number and previous line number are the same and can't be 0
        {
            if(error1==true){
            errorlines.push_back(errorline);
            cout << "TYPE MATCHES BUT WIDTH DOES NOT, ERROR. "<< "Number of errors: "<< TypeMatchNotWidth << " ERROR IS ON LINE: " << errorline<<" THE LINE WHICH CONTAINS THE ERROR IS: "<<printLine[errorline-1] << endl<< endl;
            error1=false;
            noerror=false;
            }
            else if(error2==true)
            {
            errorlines.push_back(errorline);
            cout <<"WIDTH MATCHES BUT TYPE DOES NOT, ERROR. "<< "Number of errors: "<< WidthMatchNotType << " ERROR IS ON LINE: " << errorline<<" THE LINE WHICH CONTAINS THE ERROR IS: "<<printLine[errorline-1] << endl<< endl;
            error2=false;
            noerror=false;
            }
            else if(error3==true)
            {
            errorlines.push_back(errorline);
             cout << "WIDTH AND TYPE BOTH DO NOT MATCH, ERROR. "<< "Number of errors: "<< NoWidthNoType << " ERROR IS ON LINE: " << errorline<<" THE LINE WHICH CONTAINS THE ERROR IS: "<<printLine[errorline-1]<<endl<< endl;
              error3=false;
              noerror=false;
            }
        }

    preverrorline=errorline; // moves the line so now it is on token for next line

    TypeMatch(t, errorline, ii,error1,error2,error3);
   // cout<<errorline<<" ";

    t=t->getNext();
}
if(noerror==true)
{
    cout<<"THERE ARE NO ERRORS IN TYPE OR WIDTH. " << endl<< endl;
}


/*
            cout <<"Type matches but width does not ERROR"<<" " << TypeMatchNotWidth<<endl;
            cout <<"Width matches but type does not ERROR"<<" " << WidthMatchNotType << endl;
            cout << "Width does not match and Type does not Match"<<" " << NoWidthNoType << endl;

  /* For your testing purposes only */
  /* Ensure that tokens have all type information set*/
  /* Create operator,identifier,literal, etc. tokenLists from the master list of tokens */
cout << endl ;
  t=Copy.getFirst();
bool then=false;
bool complete=true;
 ii=0; // iterator
int LineOfIf=0;
int LineOfEnd=0;
vector <int> vecIf; // holds lines starting with if
vector <int> vecEnd; // holds lines starting with endif
bool If=false; // sees if if is seen in line
bool EndIf=false;

while(t)
{
    if(t->getPrev() == nullptr) // for when first token if NOT IN REAL VHDL CODE
    {

    if(LowerString(t->getStringRep())=="if" || LowerString(t->getStringRep())=="elsif" || complete==false)
    {
        cout<<t->getStringRep()<<" ";
        complete =false;

        if  (t->getStringRep()==";" && then == false) // if sees a semi-colon before then is found it is missing a then
        {
            cout<< " MISSING 1 THEN. "<<endl<< endl;
            complete =true;
            then=false;
        }
        else if  (t->getStringRep()==";" && then == true)// if sees a semi-colon after then is found it is not missing a then
        {
            cout<<" MISSING 0 THEN. "<<endl<< endl;
            complete =true;
            then=false;
        }

        if  (LowerString(t->getStringRep())=="then") // if sees then
        {
            then =true; // then is found
        }

       }
    }

else if((LowerString(t->getStringRep())=="if" &&LowerString(t->getPrev()-> getStringRep()) != "end") || LowerString(t->getStringRep())=="elsif" || complete==false)//when not an end if or is an else if
    {
        cout<<t->getStringRep()<<" ";
        complete =false;

        if  (t->getStringRep()==";" && then == false)
        {
            cout<< " MISSING 1 THEN. "<<endl<< endl;
            complete =true;
            then=false;
        }
        else if  (t->getStringRep()==";" && then == true)
        {
            cout<<" MISSING 0 THEN. "<<endl<< endl;
            complete =true;
            then=false;
        }

        if  (LowerString(t->getStringRep())=="then")
        {
            then =true;
        }

    }


MissingEndIf(t,ii,LineOfIf,LineOfEnd,If,EndIf);
    if(If==true) // if if is found
    {
    vecIf.push_back(LineOfIf); // holds line if was found on
    If=false; // then resets
    }
    if(EndIf==true)
    {
    vecEnd.push_back(LineOfEnd); // holds line end if is found on
    EndIf=false;// reset
    }


t=t->getNext();
}
int IfmissingEnd=0;
if(vecIf.size()!=vecEnd.size()) // if number of if does not equal number of else ifs
{
    IfmissingEnd=vecIf.size()-vecEnd.size(); // difference
    for(unsigned i=0;i<IfmissingEnd;i++)
    {
    cout<<"LINE "<<vecIf[i]<< " IS MISSING AN END IF."<<"THE LINE WHICH CONTAINS THE ERROR IS: " <<printLine[vecIf[i]-1] << endl<< endl; // for every end if missing if outputs the line and number

    }

}
else
{
    cout << "THERE IS NO MISSING END IFS IN THIS VHD FILE. " << endl<< endl;
}
    cout << "THE NUMBER OF CONDITIONAL EXPRESSIONS ARE: " << CondExp<< endl;

}
cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;


if(LowerString(mode) == "bonus")
{
t=Copy.getFirst();
unsigned int ii=0;
int LineOfIf=0;
int LineOfEnd=0;
vector <int> vecIf;
vector <int> vecEnd;
bool If=false;
bool EndIf=false;

while (t)
{
    MissingEndIf(t,ii,LineOfIf,LineOfEnd,If,EndIf); // function call returns
    if(If==true)
    {
    vecIf.push_back(LineOfIf);
    If=false;
    }
    if(EndIf==true)
    {
    vecEnd.push_back(LineOfEnd);
    EndIf=false;
    }
t=t->getNext();
}

int IfmissingEnd=0;
if(vecIf.size()!=vecEnd.size())
{
    IfmissingEnd=vecIf.size()-vecEnd.size();
    for(unsigned i=0;i<IfmissingEnd;i++)
    {
    cout<<"LINE "<<vecIf[i]<< " IS MISSING AN END IF."<<"THE LINE WHICH CONTAINS THE ERROR IS: " <<printLine[vecIf[i]-1]<<endl << endl;

    }

}
else
{
    cout << "NO MISSING END IF IN THIS VHD FILE. " << endl<< endl;
}
int NumSemiC;
int NumSymbol;
int NumEndif;
bool noprob = true;

for(unsigned ii=0;ii<printLine.size();ii++)
{
    NumSymbol=0;
    NumSemiC=0;
    NumEndif=0;

    NumSymbol=printLine[ii].find("<=",0);
    NumSemiC=printLine[ii].find(";",0);
    NumEndif=printLine[ii].find("end",0);

    if((NumSymbol!=-1 && NumEndif==-1) || (NumSymbol==-1 && NumEndif!=-1))//if the <= symbol or end if is there then search for if semicolon is on that line
    {
        if(NumSemiC==-1)//semicolon does not exist on this line
        {
        cout<<"LINE "<<ii<<" \""<<printLine[ii]<<"\" IS MISSING A SEMICOLON."<<endl<< endl;
        noprob = false;// set to false if semicolon is missing
        }
        else
        {
            //do nothing
        }
    }
    else
    {
        //do nothing
    }
 }
 if(noprob == true)//it is true if there is no missing semicolon
    {
         cout << "THERE IS NO MISSING SEMICOLON IN THIS VHD FILE. " << endl<< endl;
    }
}

return 0;
    }
