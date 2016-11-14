// Will Fritz
// 11/7/2016
// Interface for Lifeboard class

class Lifeboard {
	public:
		Lifeboard();
		~Lifeboard();
        void kill(int, int);
		void revive(int, int);
        void addCount();
		void print();
        void advance();
	private:
        char board[42][42];
        int count[42][42];
};
		
