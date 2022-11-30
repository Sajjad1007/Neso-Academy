## **Algorithm 1. To convert an expression from infix to postfix using stack**

Scan the symbols of the given expression from left to right and for each symbol, do the following :

If symbol is an operand then
- Print that symbol onto the screen.

Else if symbol is a left parenthesis then
- Push it onto the stack.

Else if symbol is a right parenthesis then
- Pop all the operators from the stack upto the first left parenthesis and print them on the screen.
- Discard the left and right parenthesis.

Else if symbol is an operator then
- If the precedence of the operators in the stack are greater than or equal to the current operator then
    - Pop the operators out of the stack and print them on the screen.
    - Push the current operator onto the stack.
- Else
    - Push the current operator onto the stack.

The expression printed on the screen is the determined postfix expression of the given infix expression.

## **Algorithm 2. To evaluate a postfix expression using stack**

Scan the symbols of the given postfix expression from left to right and for each symbol, do the following :

If symbol is an operand then
- Push it onto the stack.

Else if symbol is an operator then
- Pop two symbols out of the stack and apply the operator on these symbols.
- Push the result onto the stack.

After scanning all the symbols of the postfix expression,
- Pop the remaining symbol out of the stack.
- Print it on the screen.

The remaining symbol is the result obtained after evaluating the postfix expression. 