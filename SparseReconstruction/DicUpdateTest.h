#pragma once
// Add library support for OpenMesh
#include	"TriMesh.h"
#include	"DictionaryUpdate.h"



class DicUpdateTest
{
public:
	DicUpdateTest(TriMesh _mesh_);
	~DicUpdateTest();
	TriMesh							solver();  // Return the Mesh after Dictionary Update

private:
	void							compute(Eigen::SparseMatrix<double> &);	// Compute P, B, V for Dictionary Update 

	TriMesh							mesh_;
	Eigen::MatrixXd					P_;
	//Eigen::SparseMatrix<double>		B_;
	Eigen::MatrixXd					V_;


};
