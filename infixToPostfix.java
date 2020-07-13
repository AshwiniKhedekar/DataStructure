/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class infToPostfix {
    private static int preced(char op)
    {
        switch(op)
        {
            case '^':
                return 4 ;
            case '*':
            case '/':
                return 3 ;
            case '+':
            case '-':
                return 2 ;
            case '(':
                return 1 ;
            default :
                return 0;
        }
    }
	public static void main (String[] args) {
		//code
		String str;
		Scanner sc= new Scanner(System.in);
		Stack<Character> st = new Stack<Character>();
		str = sc.next();
		char[]infix=str.toCharArray();
		for(int i=0;i<infix.length;i++)
		{
            if(infix[i]=='(')
                st.push(infix[i]);
            else if(Character.isLetterOrDigit(infix[i]))
                System.out.print(infix[i]);
            else if(infix[i]==')')
            {
                while(!st.empty() && st.peek()!='(')
                {
                        System.out.print(st.pop());
                }
                if(st.peek()=='(')
                    st.pop();
            }
            else if(st.empty())
            {
                    st.push(infix[i]);
            }
            else if(st.peek()=='(' || preced(infix[i]) > preced(st.peek()))
                    st.push(infix[i]);
            else
            {
               while(!st.empty() && preced(infix[i]) <= preced(st.peek()))
                {
                        System.out.print(st.pop());
                }
                st.push(infix[i]);
            }
		}
		while(!st.empty() && st.peek()!='(')
		    System.out.print(st.pop());
	}
}
