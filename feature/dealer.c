// dealer.c ����
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
                return notify_fail("Ŀǰû�п������Ķ�����\n");
        if(nature=="event_night"){
                message_vision("$NЦ�Ŷ�$n˵��:С��ոմ���,��λ" + respect
                + "�����������ɡ�\n", this_object(),this_player());
                return 1;
        }
        if(nature=="event_midnight"){
                message_vision("$N�������ͷ���$n˵��:"+rude+",��ҹ�����˻���ʲô��,���������ɡ�\n", this_object(),this_player());
                switch(random(2))
                   {case 0 : this_object()->command("zzz");break;
              case 1 : this_object()->command("zzz "+this_object()->query("id"));
               break;}
                return 1;
        }
        if(nature=="event_dawn"){
                message_vision("$NЦ�Ŷ�$n˵��:��λ" + respect
                + ",���Ҫ���ˣ����ĵȵȰɡ�\n", this_object(),this_player());
                return 1;
        }                       

        printf("�������%s����������Ʒ��\n", query("name"));
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

                        str += sprintf("%s��%s%s\n", str1,
                        "ÿ" + data[l]["unit"] + "����  ", MONEY_D->price_str(data[l]["value"] * 6 / 5));
/*
                        str += sprintf("%s%30-s��%s\n", chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"],
                        MONEY_D->price_str(data[l]["value"] * 6 / 5));
*/
                }
        }

        if (arrayp(goods = query("vendor_goods")))
                for (i = 0; i < sizeof(goods); i++)
                {
                        str = sprintf("%s%30-s��%s\n", str, goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
                }

        if (str =="")
                return notify_fail("Ŀǰû�п������Ķ�����\n");

        this_player()->start_more(str);
        return 1;
}

int do_buy(string arg)
{
        int val_factor;
        string ob_file;
        object ob;
        mapping fam;

        if ( (fam = this_player()->query("family")) && fam["family_name"] == "ؤ��" )
                return notify_fail("���Ǹ���л�����ʲ�ᶫ����\n");

        if(NATURE_D->room_event_fun()=="event_night") 
        {
                message_vision("$NЦ�Ŷ�$n˵��:����մ��ȣ������������ɡ�\n",this_object(),this_player());
                return 1;
        }
     if(NATURE_D->room_event_fun()=="event_midnight") 
        {
                message_vision("$N�����Ĳ��ͷ���$n˵��:��ҹ�����ģ���ʲô������������!\n", this_object(),this_player());
                return 1;
        }
        if(NATURE_D->room_event_fun()=="event_dawn") 
        {
                message_vision("$NЦ�Ŷ�$n˵��:���Ҫ���ˣ������ĵȵȰɡ�\n",this_object(),this_player());
                return 1;
        }        
        if (!arg)
                return notify_fail("������ʲô��\n");
        else if (!(ob = present(arg, this_object())))
                if ((ob_file = is_vendor_good(arg)) == "")
                        return notify_fail("������ʲô��\n");

        if (!ob) {
                ob = new(ob_file);
                val_factor = 10;
        }
        else {
                if (ob->query("equipped"))
                        return notify_fail("������ʲô��\n");
                val_factor = 12;
        }

        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");


        switch (MONEY_D->player_pay(this_player(), ob->query("value") *  val_factor / 10)) {
        case 0:
                return notify_fail("��⵰��һ�ߴ���ȥ��\n");
        case 2:
                return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
        default:
                set_temp("busy", 1);
                message_vision("$N��$n����������һ" + ob->query("unit") +
                ob->query("name") + "��\n", this_player(), this_object());
                if ( this_player()->over_encumbranced() ) {
                        ob->move(environment(this_player()));
                        write(ob->query("name") + "��������˵̫���ˣ���ֻ�ð������ڵ��ϡ�\n");
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
                return notify_fail("��Ҫ��ʲô�ļۣ�\n");
          if(NATURE_D->room_event_fun()=="event_night") 
        {
                message_vision("$NЦ�Ŷ�$n˵��:����մ��ȣ������������ɡ�\n",this_object(),this_player());
                return 1;
        }
     if(NATURE_D->room_event_fun()=="event_midnight") 
        {
                message_vision("$N�����Ĳ��ͷ���$n˵��:��ҹ�����ģ���ʲô������������!\n", this_object(),this_player());
                return 1;
        }
        if(NATURE_D->room_event_fun()=="event_dawn") 
        {
                message_vision("$NЦ�Ŷ�$n˵��:���Ҫ���ˣ������ĵȵȰɡ�\n",this_object(),this_player());
                return 1;
        }
        if (ob->query("money_id"))
                return notify_fail("��û�ù�Ǯ����\n");

        if (userp(ob))
                ob->set("value", ob->query("per") * 500);

        value = ob->query("value");
        if (value < 1)
                write(ob->query("name") + "һ�Ĳ�ֵ��\n");
        else
                write(ob->query("name") + "ֵ" +
                MONEY_D->price_str(value * 70 / 100) + "��\n");
        return 1;
}

int do_sell(string arg)
{
        object ob;
        int value;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

          if(NATURE_D->room_event_fun()=="event_night") 
        {
                message_vision("$NЦ�Ŷ�$n˵��:����մ��ȣ������������ɡ�\n",this_object(),this_player());
                return 1;
        }
     if(NATURE_D->room_event_fun()=="event_midnight") 
        {
                message_vision("$N�����Ĳ��ͷ���$n˵��:��ҹ�����ģ���ʲô������������!\n", this_object(),this_player());
                return 1;
        }
        if(NATURE_D->room_event_fun()=="event_dawn") 
        {
                message_vision("$NЦ�Ŷ�$n˵��:���Ҫ���ˣ������ĵȵȰɡ�\n",this_object(),this_player());
                return 1;
        }
        if ( query_temp("busy") )
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");
        if (ob->query("money_id"))
                return notify_fail("��������Ǯ������\n");

        if (stringp(ob->query("no_drop")) || ob->query("no_sell") )
                return notify_fail("����������������\n");

        if (is_vendor_good(arg) != "")
                return notify_fail("������ò��ã�\n");

        if (ob->query("food_supply"))
                return notify_fail("ʣ��ʣ���������Լ��ðɡ�\n");

        if (ob->query("shaolin"))
                return notify_fail("С��ֻ��һ���Դ����ɲ��������������\n");

        if ( userp(ob) && ob->query("age") >= 18 )
        {
                ob->set("value", ob->query("per") * 500);
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("%s��ĳ�˹���������ˡ�", ob->name(1)));
        }

        value = ob->query("value");
        if (value < 30)
                write(ob->query("name") + "һ�Ĳ�ֵ��\n");
        else {
                message_vision("$N������һ" + ob->query("unit") +
                ob->query("name") + "��$n��\n", this_player(), this_object());
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

