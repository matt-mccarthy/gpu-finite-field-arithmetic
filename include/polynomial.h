#include<memory>

namespace gpu_finite_field
{

class polynomial
{
	public:
		polynomial(const unsigned* coeffs, unsigned degree, unsigned charecteristic);
		polynomial(polynomial&& move_me);
		~polynomial()
		
		unsigned	get_degree();
		unsigned	get_charecteristic();
		unsigned*	get_coeffs();
		polynomial&	copy();
		
		static polynomial& operator+(const polynomial& p, const polynomial& q);
		static polynomial& operator-(const polynomial& p, const polynomial& q);
		static polynomial& operator*(const polynomial& p, const polynomial& q);
		static polynomial& operator*(unsigned constant, const polynomial& p);
		
	private:
		polynomial(std::shared_ptr<unsigned> coeffs, unsigned degree, unsigned charecteristic);
	
		std::shared_ptr<unsigned> 	coeffs;
		unsigned 					degree;
		unsigned 					charecteristic;
}

};
