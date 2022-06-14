
#ifndef VECTOR_ITERATOR_TPP
# define VECTOR_ITERATOR_TPP

namespace ft
{

/*----------------------------------------------------------------------------*/
/*---------------------- Constructors && Destructor --------------------------*/
/*----------------------------------------------------------------------------*/

template<class Vector>
vector_iterator<Vector>::vector_iterator(void) : _ptr(NULL)
{
}

template<class Vector>
vector_iterator<Vector>::vector_iterator(typename vector_iterator::pointer ptr) : _ptr(ptr)
{
}

template<class Vector>
vector_iterator<Vector>::vector_iterator(vector_iterator const & src) : _ptr(src._ptr)
{
}

template<class Vector>
vector_iterator<Vector>&	vector_iterator<Vector>::operator=(vector_iterator const & rhs)
{
	this->_ptr = rhs._ptr;
	return (*this);
}

template<class Vector>
vector_iterator<Vector>::~vector_iterator(void)
{
}

/*----------------------------------------------------------------------------*/
/*------------------- pre_increment and post_increment -----------------------*/
/*----------------------------------------------------------------------------*/

template<class Vector>
typename vector_iterator<Vector>::pointer	vector_iterator<Vector>::operator++(void)
{
	return (++this->_ptr);
}

template<class Vector>
typename vector_iterator<Vector>::pointer	vector_iterator<Vector>::operator++(int)
{
	typename vector_iterator::pointer	copyPtr;

	copyPtr = ++this->_ptr;
	return (copyPtr);
}

/*----------------------------------------------------------------------------*/
/*------------------- equality/inequality comparisons ------------------------*/
/*----------------------------------------------------------------------------*/

template<class Vector>
bool	vector_iterator<Vector>::operator==(vector_iterator const & rhs) const
{
	return (this->_ptr == rhs._ptr);
}

template<class Vector>
bool	vector_iterator<Vector>::operator!=(vector_iterator const & rhs) const
{
	return (this->_ptr != rhs._ptr);
}

/*----------------------------------------------------------------------------*/
/*-------------------      dereferencing operators    ------------------------*/
/*----------------------------------------------------------------------------*/

template<class Vector>
typename vector_iterator<Vector>::reference	vector_iterator<Vector>::operator*(void)
{
	return (*this->_ptr);
}

}

#endif

























