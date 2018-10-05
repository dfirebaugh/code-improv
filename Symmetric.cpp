/*************************************************************
	The user inputs an  Eigen::Matrix
	and SymMat class provides a Symmetric Matrix for this 
	input Matrix
**************************************************************/
#include"Symmetric.h"
#include<iostream>
using namespace Eigen;
#if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900)
#include <thread>
#endif
int THREADS_NUMBER = 4;   // number of threads being used
/************************************************************
			Constructor definition
*************************************************************/

template<typename _Scalar> 
SymMat<_Scalar>::SymMat()
{

		_Rows =_Cols = 0;
		symmatrix ;
}

template<typename _Scalar> template<typename type,int r,int c>
SymMat<_Scalar>::SymMat(Eigen::Matrix<type,r,c>M)
	{
		long long int _Dimension  = M.rows();		//gets the dimension of the Eigen::Matrix ,rows == cols
		_Rows = _Dimension;
		_Cols = _Dimension;
		

/***********************************************************
	 Throwing an Exception if dimension 
	 provided by the user is less than zero
***********************************************************/
		try {
				if(_Dimension < 0) 
				{
					throw _Dimension;
				}

			}
		catch(ll num) 
		{
			std::cout<<"Exception: "<<"\n"<<"You cannot enter "<<num<<" as a dimension."<<"\n";
			exit(0);
		}//Exception Handling ends here 

		for(ll i=0;i<_Rows;i++)
		{
			for(ll j =i;j<_Cols;j++)
			{
				
				symmatrix.push_back(M(i,j));								// Store in Row Major Order
			}
		}
	}// Constructor ends here 


/*********************************************************************
  Implementing the Matrix indexing i.e S(i,j) = S[i][j] i.e Accessor
  using operatpr () overloading 
**********************************************************************/
template<typename _Scalar> 
_Scalar  SymMat<_Scalar>::operator()(ll i,ll j)
{
    if (i <= j)
    return symmatrix[(i * _Rows - (i - 1) * i / 2 + j - i)];
  	else
    return symmatrix[(j * _Rows - (j - 1) * j / 2 + i - j)];
}

/*Using this output stream overloading for printing the matrix*/ 
template<typename _Scalar>
inline std::ostream &operator <<( std::ostream &out,  const SymMat<_Scalar> & m){
		 
		 std::cout<<"\n";
		 for(ll i=0;i<m._Rows;i++)
		  {
		  	for (ll j=0;j<m._Cols;j++)
		  	{  
		  	  
		  		if (i <= j)
		      	 out << m.symmatrix[(i * m._Rows - (i - 1) * i / 2 + j - i)] << " ";
		  		 else
		      	 out <<  m.symmatrix[(j * m._Rows - (j - 1) * j / 2 + i - j)] << " ";

		  	}
		  	std::cout<<"\n";
		  }std::cout<<"\n";
		
		 return out;
	}

/***************************************************************************************
	Uisng Operator/Function Overloading equalization:
	SymMat = SymMat
****************************************************************************************/

template<typename _Scalar>
SymMat<_Scalar> SymMat<_Scalar>:: operator =(SymMat<_Scalar> const &ob2)
{
	SymMat<_Scalar> result;
	result->_Rows = ob2._Rows;
	result->_Cols = ob2._Cols;
	result->symmatrix = ob2.symmatrix;
}

/***************************************************************************************
	Uisng Operator/Function Overloading for Addition :
	SymMat + SymMat
	SymMat + Eigen::Matrix
****************************************************************************************/

// Addition of SymMat + SymMat
template<typename _Scalar>
SymMat<_Scalar> SymMat<_Scalar>:: operator +(SymMat<_Scalar> const &ob2)
{
	//Throw Exception if size of both the SymMat are not same 
	try {
				if(_Rows!=ob2._Rows) 
				{
					throw _Rows;
				}

		}
		catch(ll num) 
		{
			std::cout<<"Exception: "<<"\n"<<"The given SymMats for addition don't have same dimension"<<"\n";
			exit(0);
			
		}
	ll length = _Rows;
	SymMat<_Scalar> result = ob2;
	for(ll i =0;i<length*(length+1)/2;i++)
	{
		result.symmatrix[i] = (this->symmatrix[i] + ob2.symmatrix[i]);
		
	}
	return result;
}


// Addition of SymMat + Eigen::Matrix
template<typename _Scalar>
Eigen::MatrixXd  SymMat<_Scalar>:: operator +(Eigen::MatrixXd &m)
{

	//Throw Exception if size of SymMat and Eigen::Matrix are not same 
	try {
				if(this->_Rows!=m.rows() || this->_Rows!=m.cols() || m.cols()!=m.rows()) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<"\n"<<"The given SymMat and Eigen:: Matrix for addition don't have same dimension"<<"\n";
		exit(0);
		
	}

	//Throw Exception if size of anyone of  the SymMat or Eigen::Matrix is zero
	try {
				if(this->_Rows==0 || m.rows()==0 || m.cols()==0) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<"\n"<<"Zero sized Matrix found for Addition"<<"\n";
		exit(0);
		
	}

	//Throw Exception if data type of both the SymMat are not same 
	try {
				if(typeid(m(0,0)).name() != typeid(this->symmatrix[0]).name()) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<"\n"<<"Two Matrix of different data types"<<"\n";
		exit(0);
		
	}

	ll length = this->_Rows;
	Eigen::MatrixXd result = m;
	for(ll i =0;i<length;i++)
	{
		for(ll j=0;j<length;j++)
		{
			_Scalar temp  ;
			if (i <= j)
	      	temp = this->symmatrix[(i * length - (i - 1) * i / 2 + j - i)];
	  		if(i>j)
	      	temp = this->symmatrix[(j * length - (j - 1) * j / 2 + i - j)];

			result(i,j) = temp + m(i,j);
		}
		
		
	}
	return result;
}

/*************************************************
Subtraction of Two Matrix
*************************************************/

//1. Difference btw SymMat and SymMat
template<typename _Scalar>
SymMat<_Scalar> SymMat<_Scalar>:: operator -(SymMat<_Scalar> const &ob2)
{
	//Throw Exception if size of both the SymMat are not same 
	try {
				if(this->_Rows!=ob2._Rows) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<"\n"<<"The given SymMats for addition don't have same dimension"<<"\n";
		exit(0);
		
	}
	ll length = this->_Rows;
	SymMat<_Scalar> result = ob2;
	for(ll i =0;i<length*(length+1)/2;i++)
	{
		result.symmatrix[i] = (this->symmatrix[i] - this->symmatrix[i]);
		
	}
	return result;
}// This function ends here 


// Subtraction of SymMat + Eigen::Matrix
template<typename _Scalar>
Eigen::MatrixXd  SymMat<_Scalar>:: operator -(Eigen::MatrixXd &m)
{

	//Throw Exception if size of SymMat and Eigen::Matrix are not same 
	try {
				if(this->_Rows!=m.rows() || this->_Rows!=m.cols() || m.cols()!=m.rows()) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<"\n"<<"The given SymMat and Eigen:: Matrix for addition don't have same dimension"<<"\n";
		exit(0);
		
	}

	//Throw Exception if size of anyone of  the SymMat or Eigen::Matrix is zero
	try {
				if(this->_Rows==0 || m.rows()==0 || m.cols()==0) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<"\n"<<"Zero sized Matrix found for Addition"<<"\n";
		exit(0);
		
	}

	//Throw Exception if data type of both the SymMat are not same 
	try {
				if(typeid(m(0,0)).name() != typeid(this->symmatrix[0]).name()) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<"\n"<<"Two Matrix of different data types"<<"\n";
		exit(0);
		
	}

	ll length = this->_Rows;
	Eigen::MatrixXd result = m;
	for(ll i =0;i<length;i++)
	{
		for(ll j=0;j<length;j++)
		{
			_Scalar temp  ;
			if (i <= j)
	      	temp = this->symmatrix[(i * length - (i - 1) * i / 2 + j - i)];
	  		if(i>j)
	      	temp = this->symmatrix[(j * length - (j - 1) * j / 2 + i - j)];

			result(i,j) = temp - m(i,j);
		}
		
		
	}
	return result;
}// This function ends here 

/***************************************************************************
	Product btw two Matrix
****************************************************************************/

//1. Product btw SymMat and SymMat
template<typename _Scalar>
Eigen:: MatrixXd SymMat<_Scalar>:: operator *(SymMat<_Scalar> const &ob2)
{
	//Throw Exception if size of both the SymMat are not same 
	try {
				if(this->_Rows!=ob2._Rows) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<"\n"<<"The given SymMats for addition don't have same dimension"<<"\n";
		exit(0);
		
	}
	ll length = this->_Rows;
	Eigen:: MatrixXd result(length,length);
    for (ll i = 0; i < length; i++)
    {
        for (ll j = 0; j < length; j++)
        {
            result(i,j) = 0;
            for (ll k = 0; k < length; k++)
            {
            		
	            	_Scalar temp1,temp2  ;
					if (i <= k)
			      	temp1 = this->symmatrix[(i * length - (i - 1) * i / 2 + k - i)];
			  		if(i>k)
			      	temp1 = this->symmatrix[(k * length - (k - 1) * k / 2 + i - k)];
			      
			      	if (k <= j)
			      	temp2 = ob2.symmatrix[(k * length - (k - 1) * k / 2 + j - k)];
			  		if(k>j)
			      	temp2 = ob2.symmatrix[(j * length - (j - 1) * j / 2 + k - j)];

	                result(i,j) += temp1*temp2;
            }
        }
    }
    return result;
} // This function ends here 


//2. Product btw SymMat and Eigen::Matrix

//This is the threading part
#if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900)	//compiles only if c++ is supported 

template<typename _Scalar>
void  multiply_threading(SymMat<_Scalar> const &m1,Eigen::MatrixXd &result, const int thread_number,Eigen::MatrixXd &m2) {
  // Calculate workload
  int MATRIX_SIZE = m1._Rows;
  
  const int n_elements = (MATRIX_SIZE * MATRIX_SIZE);
  const int n_operations = n_elements / THREADS_NUMBER;
  const int rest_operations = n_elements % THREADS_NUMBER;

  int start_op, end_op;
  ll length = m1._Rows;

  if (thread_number == 0) {
    // First thread does more job
    start_op = n_operations * thread_number;
    end_op = (n_operations * (thread_number + 1)) + rest_operations;
  }
  else {
    start_op = n_operations * thread_number + rest_operations;
    end_op = (n_operations * (thread_number + 1)) + rest_operations;
  }

  for (int op = start_op; op < end_op; ++op) {
    const int row = op % MATRIX_SIZE;
    const int col = op / MATRIX_SIZE;
    double r =0;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
       double e1;
      double e2 = m2(i,col);
      
      if (row <= i)
      e1 = m1.symmatrix[(row * length - (row - 1) * row / 2 + i - row)];
      else
      e1 = m1.symmatrix[(i * length - (i - 1) * i / 2 + row - i)];
      r += e1 * e2;
    }

    result(row,col) = r;
  }
}

#endif // ends the compiler check



#if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900)	//compiled only if c++11 is supported

template<typename _Scalar> 
Eigen:: MatrixXd SymMat<_Scalar>:: operator *(Eigen::MatrixXd &m)
{

  //Throw Exception if size of SymMat and Eigen::Matrix are not same 
  try {
        if(this->_Rows!=m.rows() || this->_Rows!=m.cols() || m.cols()!=m.rows()) 
        {
          throw this->_Rows;
        }

    }
  catch(ll num) 
  {
    std::cout<<"Exception: "<<"\n"<<"The given SymMat and Eigen:: Matrix for addition don't have same dimension"<<"\n";
    exit(0);
    
  }

  //Throw Exception if size of anyone of  the SymMat or Eigen::Matrix is zero
  try {
        if(this->_Rows==0 || m.rows()==0 || m.cols()==0) 
        {
          throw this->_Rows;
        }

    }
  catch(ll num) 
  {
    std::cout<<"Exception: "<<"\n"<<"Zero sized Matrix found for Multplication"<<"\n";
    exit(0);
    
  }

  //Throw Exception if data type of both the SymMat are not same 
  try {
        if(typeid(m(0,0)).name() != typeid(this->symmatrix[0]).name()) 
        {
          throw this->_Rows;
        }

    }
  catch(ll num) 
  {
    std::cout<<"Exception: "<<"\n"<<"Two Matrix of different data types"<<"\n";
    exit(0);
    
  }

  ll length = this->_Rows;
  MatrixXd result(length,length);
 
  if(length>=50)		//runs the threading part only if the size of matrices are higher than 50
  {
  	 // Create an array of threads
	  std::thread threads[THREADS_NUMBER];

	  for (int i = 0; i < THREADS_NUMBER; ++i) {
	    // Initialize each thread with the function responsible of multiplying only a part of the matrices
	    
	    threads[i] = std::thread(&multiply_threading <_Scalar>,std::ref(*this), std::ref(result), i, std::ref(m));
	  }

	  for (int i = 0; i < THREADS_NUMBER; ++i) {
	    // Wait until each thead has finished
	    threads[i].join();
	  }

	  return result;
  }
  else
  {
  	Eigen::MatrixXd result(length,length);
	for (ll i = 0; i < length; i++)
    {
        for (ll j = 0; j < length; j++)
        {
        	result(i,j)=0;
            for (ll k = 0; k < length; k++)
            {
            	_Scalar temp  ;
            	
				if (i <= k)
		      	temp = this->symmatrix[(i * length - (i - 1) * i / 2 + k - i)];
		  		else
		      	temp = this->symmatrix[(k * length - (k - 1) * k / 2 + i - k)];

                result(i,j) += temp*m(k,j);
            }
        }
    }
	return result;
  }
   
}

#else 	// compiles if c++11 is not supported 
template<typename _Scalar>
Eigen:: MatrixXd SymMat<_Scalar>:: operator *(Eigen::MatrixXd &m)
{

	//Throw Exception if size of SymMat and Eigen::Matrix are not same 
	try {
				if(this->_Rows!=m.rows() || this->_Rows!=m.cols() || m.cols()!=m.rows()) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<std::endl<<"The given SymMat and Eigen:: Matrix for addition don't have same dimension"<<std::endl;
		exit(0);
		
	}

	//Throw Exception if size of anyone of  the SymMat or Eigen::Matrix is zero
	try {
				if(this->_Rows==0 || m.rows()==0 || m.cols()==0) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<std::endl<<"Zero sized Matrix found for Multplication"<<std::endl;
		exit(0);
		
	}

	//Throw Exception if data type of both the SymMat are not same 
	try {
				if(typeid(m(0,0)).name() != typeid(this->symmatrix[0]).name()) 
				{
					throw this->_Rows;
				}

		}
	catch(ll num) 
	{
		std::cout<<"Exception: "<<std::endl<<"Two Matrix of different data types"<<std::endl;
		exit(0);
		
	}

	ll length = this->_Rows;
	Eigen::MatrixXd result(length,length);
	for (ll i = 0; i < length; i++)
    {
        for (ll j = 0; j < length; j++)
        {
        	result(i,j)=0;
            for (ll k = 0; k < length; k++)
            {
            	_Scalar temp  ;
            	/*if (i <= k)
		      	 temp =  m.symmatrix[(i * m._Rows - (i - 1) * i / 2 + j - i)] << " ";
		  		 else
		      	 temp =   m.symmatrix[(j * m._Rows - (j - 1) * j / 2 + i - j)] << " ";*/
				if (i <= k)
		      	temp = this->symmatrix[(i * length - (i - 1) * i / 2 + k - i)];
		  		else
		      	temp = this->symmatrix[(k * length - (k - 1) * k / 2 + i - k)];

                result(i,j) += temp*m(k,j);
            }
        }
    }
	return result;
}// This function ends here

#endif


/************************************************************************************************************
	Different views of the Matrix :
	1. transpose()
*************************************************************************************************************/
template<typename _Scalar>
SymMat<_Scalar> SymMat<_Scalar>::transpose()
{
	std::cout<<*this;
	return *this;
}

template<typename _Scalar>
SymMat<_Scalar> SymMat<_Scalar>::transposeInPlace()
{
	std::cout<<*this;
	return *this;
}

template<typename _Scalar>
_Scalar SymMat<_Scalar>::trace()
{
	_Scalar sum =0;
	int check = this->_Rows;
	int next =0;

	while(next<(this->symmatrix).size())
	{
		sum = sum + (this->symmatrix[next]);
		next = next + check;
		check = check - 1;
	}
	return sum;
}
