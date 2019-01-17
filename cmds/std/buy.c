// /cmds/std/buy.c

// by QingP



inherit F_CLEAN_UP;



int main(object me, string arg)

{

	object vendor;
	int i, price;
   object* inv;



   if( this_player()->is_busy() )

        return notify_fail("你现在正忙着呢。\n");



   if( !environment(me) )

     return notify_fail("你要跟谁买东西？\n");



   inv = all_inventory(environment(me));

   i = sizeof (inv);

   while (i--) {

     if (inv[i]->is_vendor()) {

       vendor = inv[i];

       break;

     }

   }

   if (!vendor) {

     inv = all_inventory(environment(me));

     i = sizeof (inv);

     while (i--) {

       if (inv[i]->is_vendor_npc()) {

         vendor = inv[i];

         break;

       }

     }

     if (!vendor)

       return notify_fail("你要跟谁买东西？\n");

/*
     else {

       vendor->do_buy(arg);

       return notify_fail("");

     }

*/
   }





   if( !arg ) {

     return notify_fail("你想买什么？\n");

   }



   if( (price = vendor->buy_object(me, arg)) == -1 ) return 1;

   if( price < 1 ) return 0;



   if( me->can_afford(price) )

   { 

     if( me->can_afford(price) == 2 ) 

       return notify_fail("您的零钱不够了，银票又没人找得开。\n");



     else if(vendor->complete_trade(me, arg)) {

       me->pay_money(price);

       return 1;

     }

   }

   else return notify_fail("穷光蛋，一边呆着去！\n");

}
