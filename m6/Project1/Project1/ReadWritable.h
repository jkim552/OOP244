/* ------------------------------------------------------
Final Project Milestone 3
Module: ReadWritable
Filename: ReadWritable.h
Version 1.0
Author	Junhee Kim
Revision History
-----------------------------------------------------------
Date      Reason
2020/07/17  Preliminary release
2020/07/20 Reused from MS4
-----------------------------------------------------------*/
#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
#include <iostream>

namespace sdds {
	class ReadWritable {
		bool flag;
	public:
		ReadWritable();
		virtual ~ReadWritable();
		bool isCsv() const;
		void setCsv(bool value);
		virtual std::istream& read(std::istream& is);
		virtual std::ostream& write(std::ostream& os) const;
	};
	std::istream& operator>>(std::istream& is, ReadWritable& r);
	std::ostream& operator<<(std::ostream& os, const ReadWritable& w);
}




#endif // !SDDS_READWRITABLE_H
