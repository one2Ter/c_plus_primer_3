//智能指针类
class U_Ptr {
	friend class BHasPtr;//将智能指针变成class的友元类
private:
	int *ip;
	size_t use;//计数
	U_Ptr(int *p) :ip(p), use(1) {}//初始化的时候有一个指针，指针数量是1
	~U_Ptr() { delete ip; }
};

class BHasPtr {
public:
	BHasPtr(int *p, int i) :ptr(new U_Ptr(p)), val(i) {}

	BHasPtr(const BHasPtr &orig) :ptr(orig.ptr), val(orig.val)
	{
		++ptr->use;
	}

	BHasPtr& operator=(const BHasPtr &rhs);
	~BHasPtr()
	{
		if (--ptr->use == 0)
		{
			delete ptr;
		}
	}

	int *get_ptr() const { return ptr->ip; }
	int get_int() const { return val; }

	void set_ptr(int *p) { ptr->ip = p; }
	void set_int(int i) { val = i; }

	int get_ptr_val() const { return *ptr->ip; }
	void set_ptr_val(int val) const { *ptr->ip = val; }

private:
	int val;
	//int *ptr;
	U_Ptr *ptr;//智能指针类
};
BHasPtr& BHasPtr::operator=(const BHasPtr &rhs)
{
	++rhs.ptr->use;
	if (--ptr->use == 0) delete ptr;

	ptr = rhs.ptr;
	val = rhs.val;
	return *this;
}
