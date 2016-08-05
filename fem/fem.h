

#pragma once


namespace ezfem
{

class Fem
{
public:
        Fem() = default;
	Fem(const unsigned i_dim): dimension_(i_dim){};
private:
	const unsigned dimension_ = 1;
};// class Fem






}// namespace ezfem
