natural DIV_NN_N(const natural n1, const natural n2)
{
	natural x,y,z,sum;
	if (NZER_N_B(n1))
	{
		x.count=0;
		x=NEWN_N_N(x);
		return x;
	};
	if (NZER_N_B(n2))
	{
		x=DELZ_N_N(n1);
		y=ADD_1N_N(x);
		DELN_N(x);
		return y;
	};
	x=DELZ_N_N(n1);
	y=DELZ_N_N(n2);
	switch (COM_NN_D(x,y))
	{
		case 0:
			DELN_N(x);
			x.count=1;
			x=NEWN_N_N(x);
			x.digits[0]=1;
			DELN_N(y);
			return x;
		break;
		case 2:
			DELN_N(x);
			DELN_N(y);
			x.count=0;
			x=NEWN_N_N(x);
			return x;
		break;
	};
	sum.count=0;
	sum=NEWN_N_N(sum);
	while (COM_NN_D(x,y)<2)
	{
		natural w,p;
		z=DIV_NN_Nk(x,y);
		p=MUL_NN_N(z,y);
		w=SUB_NN_N(x,p);
		DELN_N(x);
		x=w;
		DELN_N(p);
		p=ADD_NN_N(sum,z);
		DELN_N(sum);
		sum=p;
		DELN_N(z);
	};
	return sum;
};
