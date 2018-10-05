from tkinter import *
from easygui import*
from numpy import *
import math
import solution as sy


''' The basic concept of this algorithm is that first we convert the Input 
Agumented matrix into Upper Triangular Matrix in Row echelon form ( https://en.wikipedia.org/wiki/Row_echelon_form ) by performing 
the following operations :
1. Swapping Two Rows
2. Multiplying a row by a non-zero scalor element
3. Adding a multiple of one row to another row
'''
''' Two processes are required for it 
    1. Forward elimination(matrix) - > To convert the given input matrix in Row echelon form . Seeing the conditions we can tell whether 
                                        solution exist or not.
    2. Backward Substitution(matrix) ->  To get the final solution
    '''
def swap(a,i,j,n):
    for k in range(n+1):
        temp = a[i][k]
        a[i][k] = a[j][k]
        a[j][k] = temp


def Gauss_elimination(a,n):
    singular_flag = forward_elimination(a,n)
    if singular_flag!=-1:
        msgbox("Singular Matrix")
#if the RHS of equation corresponding to zero row  is 0, * system has infinitely many solutions, else inconsistent
        if a[singular_flag][N]!=0:
             msgbox("Inconsistent System")
        else:
            msgbox("Infinite solutions")
        return
    backSub(a,n);      

def forward_elimination(a,n):
    for k in range(n):
        i_max = k #initializing maximum value for index 
        v_max = a[i_max][k]
        #find greater valued pivot if any
        for i in range(k+1,n):
            if abs(a[i][k]>v_max):
                v_max = a[i][k]
                i_max = i
        if a[k][i_max]==0:  #If singular matrix i.e division by zero can lead to exception hence no solution
            return k
        #swap the greatest value row with current row
        if i_max!=k:
            swap(a,k,i_max,n)
        for i in range(k+1,n):
            f = float(float(a[i][k])/float(a[k][k]))            
            for j in range(k+1,n+1):
                a[i][j] = float(float(a[i][j])-float(a[k][j])*float(f))
            a[i][k]=0  # Filling the lower triangular matrix with zeros
    return -1

def backSub(a,n):
    x = [0]*n
    mat = array(a)
    for i in range(n-1,-1,-1):
        x[i] = ((a[i][n]))
        for j in range(i+1,n):
            x[i] = float(float(x[i]) - (float(a[i][j])*float(x[j])))
        x[i] = (float(x[i])/float(a[i][i]))
    sy.display_answer(x)
