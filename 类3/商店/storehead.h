class sale
{
	public:
		sale(int n,int q,float p):num(n),quantity(q),price(p){};
		void total();
		static void display();
		static float average();
	private:
		int num;
		float price;
		static float discount; 
		static float sum;
		static int n;
		int quantity;
};
