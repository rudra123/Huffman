
class node
{
private:
	int freq;
	const char* data;
	node* l;
	node* r;
	node* p;
public:
	node()
	{}
	void setFreq(int f)
	{
		freq = f;
	}
	void setData(const char* s)
	{
		data = s;
	}
	void setLeft(node* a)
	{
		l = a;
	}
	void setRight(node* b)
	{
		r = b;
	}
	void setP(node* c)
	{
		p=c;
	}
	int getFreq()
	{
		return freq;
	}
	const char* getData()
	{
		return data;
	}
	node* getLeft()
	{
		return l;
	}
	node* getRight()
	{
		return r;
	}
	node* getP()
	{
		return p;
	}

};