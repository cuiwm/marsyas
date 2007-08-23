#ifndef MARSYAS_WEKADATA_H
#define MARSYAS_WEKADATA_H 

#include "MarSystem.h"
#include <list>
#include <vector>
 
namespace Marsyas
{
//This class represents a collection of row data read from a weka arff file.
//It is organized as a vector collection of vector pointers.
//It is optimized for fast sorting and shuffling of the data. It is not intended
//that the data change once it is loaded.
//
//It is also assumed that the last column of each row is the class attribute.
//All data items are mrs_real, including the class attribute, however the class
//attribute should be interpreted as an mrs_natural.
class WekaData : public std::vector<std::vector<mrs_real>*>
{
public:
	WekaData();
	virtual ~WekaData();

	//create the table. Will clear contents first and fix the number of columns.
	void Create(mrs_natural cols);

	//clear all data from the table
	void Clear();

	//randomly shuffle the data in the table
	void Shuffle();

	//sort the table based on an attribute. sorts in ascending order.
	void Sort(mrs_natural attIndex);

	//add rows of data to the table
	void Append(const realvec& in);
	void Append(std::vector<mrs_real> *);

	//return the number of columns(including the class attribute)
	inline mrs_natural getCols()const{return cols_;}
	inline mrs_natural getRows()const{return rows_;}

	//get the class attribute for a row and convert to a int
	mrs_natural GetClass(mrs_natural row)const;

	//debug helper funtion to dump table to an ascii file
	void Dump(const std::string& filename, const std::vector<std::string>& classNames)const;

private:
	mrs_natural cols_;
	mrs_natural rows_;
	//some sorting private functions
	void quickSort(mrs_natural attIndex, mrs_natural left, mrs_natural right);
	void swapRows(mrs_natural l, mrs_natural r);
	mrs_natural partition(mrs_natural attIndex, mrs_natural l, mrs_natural r);
};//class WekaData
}
#endif
