template <typename type>
class LL
{
	struct node
	{
		type data;
		node *prev;
		node *next;
	};

private:
	node *head;
	node *tail;

public:
	class iterator
	{
	public:
		friend class LL;
		iterator();
		iterator(node *);
		type operator*() const;
		const iterator &operator++(int);
		const iterator &operator--(int);
		bool operator==(const iterator &) const;
		bool operator!=(const iterator &) const;

	private:
		node *current;
	};

	/* Default */
	LL();
	~LL();
	LL(const LL<type> &);

	/* Overload */
	const LL<type> &operator=(const LL<type> &);

	/* Characteristics */
	void headInsert(const type &);
	void tailInsert(const type &);
	iterator begin() const;
	iterator end() const;
	void swapNodes(iterator &, iterator &);
};
