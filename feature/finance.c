// /feature/finance.c



#include <ansi.h>



varargs int pay_money(int amount, int checkonly)

{

	object g_ob, s_ob, c_ob;

	int gc, sc, cc, left;



	seteuid(getuid());



	if (g_ob = present("gold_money", this_object()))

		gc = g_ob->query_amount();

	else

		gc = 0;

	if (s_ob = present("silver_money", this_object()))

		sc = s_ob->query_amount();

	else

		sc = 0;

	if (c_ob = present("coin_money", this_object()))

		cc = c_ob->query_amount();

	else

		cc = 0;

	

	if (cc + sc * 100 + gc * 10000 < amount)

		if (present("thousand-cash", this_object()))

			return 2;

		else return 0;

	else if (!checkonly) {

		left = cc + sc * 100 + gc * 10000 - amount;

		gc = left / 10000;

		left = left % 10000;

		sc = left / 100;

		cc = left % 100;



		if (g_ob)

			g_ob->set_amount(gc);

		else sc += (gc * 100);

		if (s_ob)

		 	s_ob->set_amount(sc);

		else if (sc) {

			s_ob = new(SILVER_OB);

			s_ob->set_amount(sc);

			s_ob->move(this_object());

		}

		if (c_ob)

			c_ob->set_amount(cc);

		else if (cc) {

			c_ob = new(COIN_OB);

			c_ob->set_amount(cc);

			c_ob->move(this_object());

		}

		return 1;

	}

	else return 1;

}



int can_afford(int amount) { return pay_money(amount, 1); }