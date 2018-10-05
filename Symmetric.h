#ifndef SYMMAT_H
#define SYMMAT_H

#include<vector>
#include<typeinfo>
#include <eigen3/Eigen/Dense>
#define  ll long long int 				
//#include <Eigen/Dense>

/*********************************************************
	If error while compiling, comment the line :
	#include <eigen3/Eigen/Dense>  
	and	remove the comment from:
	#include <Eigen/Dense> 
 **********************************************************/


template<typename _Scalar>  
class SymMat
{
public:

	ll _Rows;									//_Rows = num of rows
	ll _Cols;									//_Cols = num of columns 
	std::vector < _Scalar > symmatrix;			//To store the upper Diagonal only ->reduces  the storage

                                                // Storing the Upper Diagonal row wise in the vector :

/************************************************************
				Constructor 
*************************************************************/

	SymMat();
	template<typename type,int r,int c>			//You can use any type of Eigen::Matrix
	SymMat(Eigen::Matrix<type,r,c>M);

	/***************************************************************************************
	Operator overloadings for:
		1. accessors()
		2. Equalization
		3. Addition 
		4. Substraction
		5. Multiplication
		6. accesing the SymMat by just object name , i.e cout<<obj;
	****************************************************************************************/
	_Scalar  operator()(ll i,ll j);
	SymMat<_Scalar> operator =(SymMat<_Scalar> const &ob2);
	SymMat<_Scalar> operator +(SymMat<_Scalar> const &ob2);
	Eigen::MatrixXd operator +(Eigen::MatrixXd &m);
	SymMat<_Scalar>  operator -(SymMat<_Scalar> const &ob2);
	Eigen::MatrixXd  operator -(Eigen::MatrixXd &m);
	Eigen:: MatrixXd operator *(SymMat<_Scalar> const &ob2);
	Eigen:: MatrixXd operator *(Eigen::MatrixXd &m);
    template<class Y>
	friend std::ostream & operator <<( std::ostream& out, const SymMat<Y> & m);

	/***************************************************************************************
		different views of the matrix:
		1.) transpose()
		2.) transposeInPlace()
		3.) trace()
	***************************************************************************************/
	SymMat<_Scalar> transpose();
	SymMat<_Scalar> transposeInPlace();
	_Scalar trace();
};


#endif // SYMMAT_H
