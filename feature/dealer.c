// dealer.c 商人
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands

#include <dbase.h>
#include <ansi.h>

int is_vendor_npc()
{
        return 1;
}

string is_vendor_good(string arg)
{
        string *goods;
        int i;

        if (arrayp(goods = query("vendor_goods")))
                for (i = 0; i < sizeof(goods); i++)
                        if (goods[i]->id(arg))
                                return goods[i];
        return "";
}

int do_list()
{
        string *goods, str, str1, str_temp,nature,respect,rude;
        object *inv;
        int i, j, k, l, m;
        mapping *data;
        nature=NATURE_D->room_event_fun();
        respect=RANK_D->query_respect(this_player());
        rude=RANK_D->query_rude(this_player());
        str = "";
        k = 0;
        data = allocate(3000);

        inv = all_inventory(this_object());

        if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
                return notify_fail("目前没有可以卖的东西。\n");
        if(nature=="event_night"){
                message_vision("$N笑着对$n说道:小店刚刚打烊,这位" + respect
                + "请天亮再来吧。\n", this_object(),this_player());
                return 1;
        }
        if(nature=="event_midnight"){
                message_vision("$N满脸不耐烦对$n说道:"+rude+",半夜三更了还吵什么吵,天亮再来吧。\n", this_object(),this_player());
                switch(random(2))
                   {case 0 : this_object()->command("zzz");break;
              case 1 : this_object()->command("zzz "+this_object()->query("id"));
               break;}
                return 1;
        }
        if(nature=="event_dawn"){
                message_vision("$N笑着对$n说道:这位" + respect
                + ",天就要亮了，耐心等等吧。\n", this_object(),this_player());
                return 1;
        }                       

        printf("你可以向%s购买下列物品：\n", query("name"));
        for (i = 0; i < sizeof(inv); i++) {
                reset_eval_cost();
                if (!inv[i]->query("equipped")
                &&  !inv[i]->query("money_id")
                &&  !inv[i]->query_temp("check_only"))
                {
                        data[k]=([]);
                        for(j = i; j < sizeof(inv); j++ )
                        {
                                reset_eval_cost();
                                if ( inv[i]->short()==inv[j]->short()
                                &&   inv[i]->query("value")==inv[j]->query("value")
                                &&   !inv[j]->query_temp("check_only") )
                                {
                                        data[k]["id"]=inv[i]->short();
                                        data[k]["unit"]=inv[i]->query("unit");
                                        data[k]["value"]=inv[i]->query("value");
                                        data[k]["num"]= data[k]["num"] + 1;
                                        inv[j]->set_temp("check_only", 1);
                                }
                                else continue;
                        }
                        k++;
                }
                else continue;
        }

        for (i = 0; i < sizeof(inv); i++)
                if ( inv[i]->query_temp("check_only") )
                        inv[i]->delete_temp("check_only");

        if (k > 0)
        {
                for (l = 0; l < k; l++)
                {
                        str1 = chinese_number(data[l]["num"])+data[l]["unit"]+data[l]["id"];
                        str_temp = str1;

                        str_temp = replace_string(str_temp, BLK,"");
                        str_temp = replace_string(str_temp, RED,"");
                        str_temp = replace_string(str_temp, GRN,"");
                        str_temp = replace_string(str_temp, YEL,"");
                        str_temp = replace_string(str_temp, BLU,"");
                        str_temp = replace_string(str_temp, MAG,"");
                        str_temp = replace_string(str_temp, CYN,"");
                        str_temp = replace_string(str_temp, WHT,"");
                        str_temp = replace_string(str_temp, HIR,"");
                        str_temp = replace_string(str_temp, HIG,"");
                        str_temp = replace_string(str_temp, HIY,"");
                        str_temp = replace_string(str_temp, HIB,"");
                        str_temp = replace_string(str_temp, HIM,"");
                        str_temp = replace_string(str_temp, HIC,"");
                        str_temp = replace_string(str_temp, HIW,"");
                        str_temp = replace_string(str_temp, NOR,"");
                        str_temp = replace_string(str_temp, BLINK,"");

                        for (m = strlen(str_temp); m < 37; m++)
                                str1 += " ";

                        str += sprintf("%s：%s%s\n", str1,
                        "每" + data[l]["unit"] + "卖价  ", MONEY_D->price_str(data[l]["value"] * 6 / 5));
/*
                        str += sprintf("%s%30-s：%s\n", chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"],
                        MONEY_D->price_str(data[l]["value"] * 6 / 5));
*/
                }
        }

        if (arrayp(goods = query("vendor_goods")))
                for (i = 0; i < sizeof(goods); i++)
                {
                        str = sprintf("%s%30-s：%s\n", str, goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
                }

        if (str =="")
                return notify_fail("目前没有可以卖的东西。\n");

        this_player()->start_more(str);
        return 1;
}

int do_buy(string arg)
{
        int val_factor;
        string ob_file;
        object ob;
        mapping fam;

        if ( (fam = this_player()->query("family")) && fam["family_name"] == "丐帮" )
                return notify_fail("你是个穷叫化，买什麽东西！\n");

        if(NATURE_D->room_event_fun()=="event_night") 
        {
                message_vision("$N笑着对$n说道:本店刚打烊，请明天再来吧。\n",this_object(),this_player());
                return 1;
        }
     if(NATURE_D->room_event_fun()=="event_midnight") 
        {
                message_vision("$N满脸的不耐烦对$n说道:半夜三更的，吵什么吵，天亮再来!\n", this_object(),this_player());
                return 1;
        }
        if(NATURE_D->room_event_fun()=="event_dawn") 
        {
                message_vision("$N笑着对$n说道:天就要亮了，您耐心等等吧。\n",this_object(),this_player());
                return 1;
        }        
        if (!arg)
                return notify_fail("你想买什么？\n");
        else if (!(ob = present(arg, this_object())))
                if ((ob_file = is_vendor_good(arg)) == "")
                        return notify_fail("你想买什么？\n");

        if (!ob) {
                ob = new(ob_file);
                val_factor = 10;
        }
        else {
                if (ob->query("equipped"))
                        return notify_fail("你想买什么？\n");
                val_factor = 12;
        }

        if (query_temp("busy"))
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");


        switch (MONEY_D->player_pay(this_player(), ob->query("value") *  val_factor / 10)) {
        case 0:
                return notify_fail("穷光蛋，一边呆着去！\n");
        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        default:
                set_temp("busy", 1);
                message_vision("$N从$n那里买下了一" + ob->query("unit") +
                ob->query("name") + "。\n", this_player(), this_object());
                if ( this_player()->over_encumbranced() ) {
                        ob->move(environment(this_player()));
                        write(ob->query("name") + "对于你来说太重了，你只好把它放在地上。\n");
                }
                else
                ob->move(this_player());
        }
          remove_call_out("enough_rest");
        call_out("enough_rest", 1);
          return 1;
}

int do_value(string arg)
{
        object ob;
        int value;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要估什么的价？\n");
          if(NATURE_D->room_event_fun()=="event_night") 
        {
                message_vision("$N笑着对$n说道:本店刚打烊，请明天再来吧。\n",this_object(),this_player());
                return 1;
        }
     if(NATURE_D->room_event_fun()=="event_midnight") 
        {
                message_vision("$N满脸的不耐烦对$n说道:半夜三更的，吵什么吵，天亮再来!\n", this_object(),this_player());
                return 1;
        }
        if(NATURE_D->room_event_fun()=="event_dawn") 
        {
                message_vision("$N笑着对$n说道:天就要亮了，您耐心等等吧。\n",this_object(),this_player());
                return 1;
        }
        if (ob->query("money_id"))
                return notify_fail("你没用过钱啊？\n");

        if (userp(ob))
                ob->set("value", ob->query("per") * 500);

        value = ob->query("value");
        if (value < 1)
                write(ob->query("name") + "一文不值！\n");
        else
                write(ob->query("name") + "值" +
                MONEY_D->price_str(value * 70 / 100) + "。\n");
        return 1;
}

int do_sell(string arg)
{
        object ob;
        int value;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("你要卖什么？\n");

          if(NATURE_D->room_event_fun()=="event_night") 
        {
                message_vision("$N笑着对$n说道:本店刚打烊，请明天再来吧。\n",this_object(),this_player());
                return 1;
        }
     if(NATURE_D->room_event_fun()=="event_midnight") 
        {
                message_vision("$N满脸的不耐烦对$n说道:半夜三更的，吵什么吵，天亮再来!\n", this_object(),this_player());
                return 1;
        }
        if(NATURE_D->room_event_fun()=="event_dawn") 
        {
                message_vision("$N笑着对$n说道:天就要亮了，您耐心等等吧。\n",this_object(),this_player());
                return 1;
        }
        if ( query_temp("busy") )
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");
        if (ob->query("money_id"))
                return notify_fail("你想卖「钱」？？\n");

        if (stringp(ob->query("no_drop")) || ob->query("no_sell") )
                return notify_fail("这样东西不能卖。\n");

        if (is_vendor_good(arg) != "")
                return notify_fail("卖给你好不好？\n");

        if (ob->query("food_supply"))
                return notify_fail("剩菜剩饭留给您自己用吧。\n");

        if (ob->query("shaolin"))
                return notify_fail("小的只有一个脑袋，可不敢买少林庙产。\n");

        if ( userp(ob) && ob->query("age") >= 18 )
        {
                ob->set("value", ob->query("per") * 500);
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("%s被某人拐卖给唐楠了。", ob->name(1)));
        }

        value = ob->query("value");
        if (value < 30)
                write(ob->query("name") + "一文不值！\n");
        else {
                message_vision("$N卖掉了一" + ob->query("unit") +
                ob->query("name") + "给$n。\n", this_player(), this_object());
                MONEY_D->pay_player(this_player(), value * 70 / 100);
                if ( userp(ob) && ob->query("age") >= 18 )
                {
                        ob->move("/d/city/cangku");
                        ob->set_temp("selled",1);
                }
                else if (value < 50)
                        destruct(ob);
                else
                        ob->move(this_object());
        }
        set_temp("busy", 1);
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);
        return 1;
}


void enough_rest()
{
        delete_temp("busy");
}

