// /cmds/std/buy.c

// by QingP



inherit F_CLEAN_UP;



int main(object me, string arg)

{

	object vendor;
	int i, price;
   object* inv;



   if( this_player()->is_busy() )

        return notify_fail("��������æ���ء�\n");



   if( !environment(me) )

     return notify_fail("��Ҫ��˭������\n");



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

       return notify_fail("��Ҫ��˭������\n");

/*
     else {

       vendor->do_buy(arg);

       return notify_fail("");

     }

*/
   }





   if( !arg ) {

     return notify_fail("������ʲô��\n");

   }



   if( (price = vendor->buy_object(me, arg)) == -1 ) return 1;

   if( price < 1 ) return 0;



   if( me->can_afford(price) )

   { 

     if( me->can_afford(price) == 2 ) 

       return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");



     else if(vendor->complete_trade(me, arg)) {

       me->pay_money(price);

       return 1;

     }

   }

   else return notify_fail("��⵰��һ�ߴ���ȥ��\n");

}
