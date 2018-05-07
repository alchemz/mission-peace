class MyCalendar{
public:
	MyCalendar(){

	}
	bool book(int start, int end){
		auto it=booked_.lower_bound(start); //return ceiling
		if(it!=booked_.cend() && it->first < end)//check is empty
			return false;
		if(it !=booked_.cbegin() && (--it)->second>start)
			return false;

		booked_[start]=end;
		return true;
	}

private:
	map<int, int>booked_;//start->end
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

 // https://leetcode.com/problems/my-calendar-i/description/
 // http://www.cnblogs.com/grandyang/p/7920253.html