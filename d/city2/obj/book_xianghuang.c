//book_xianghuang.c
#include <ansi.h>
inherit ITEM;
int do_tear(string arg);

void init()
{
        add_action("do_tear", "tear");
}

void create()
{
         set_name(YEL"����ʮ���¾���"NOR, ({"book_xianghuang"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\nһ�������ľ���,��Ƥ(binding)�ܾ��¡�\n");
                set("unit", "��");
                set("material", "paper");
        }
        setup();
}

int do_tear(string arg)
{
        int i,j;
        object me;
        string dir;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if(arg=="book_xianghuang")
        {
        message_vision("$Nһ�°Ѿ���˺�÷��顣\n", this_player());
        destruct(this_object());
        return 1;
        }

        if( sscanf(arg, "book_xianghuang %s", dir)==1 ) {
        if( dir=="binding" ) {
                if(this_object()->query("hasgot"))
                message_vision("$N����Ƥ˺��,������Ƥ�Ѿ���ȡ���ˡ�\n", this_player());
                
                else if(random((int)this_player()->query("kar")) < 20)
                 {
                this_player()->set_temp("marks/no_book_xianghuang",1);
                message_vision("$N�ͱ�����Ե��\n", this_player());
                 }
                
                else if(this_player()->query_temp("marks/no_book_xianghuang",1))
                message_vision("����ֻ��һ��Ե�֡�\n", this_player());
                
                else
                {
                i=random(1000);  
                j=random(500);
                me->add("potential",j);
                me->add("combat_exp",i);
                message_vision("$N����Ƥ˺����������Ƥ����������\n", this_player());
                message_vision("$N�Ƚ���Ƥ�ϵĵ�ͼ����������Ȼ��������յ��ˡ�\n", this_player());
                message("shout", HIR "���������š�" + HIM + "ĳ��: ��˵"  +this_player()->query("name") + "��" + NATURE_D->game_time() + "�õ������
          "YEL"����ʮ���¾���"HIM"�ڵļ�������Ƥ�����õ�"HIW"" + chinese_number(i) + ""HIM"�㾭�飬"HIW"" + chinese_number(j) + ""HIM"��Ǳ�ܡ�\n\n" NOR,users()); 

//              me->set("huanggong\haspi8", 1);
                this_object()->set("hasgot",1);  
                }
        }
        else
        {
        message_vision("$Nһ�°Ѿ���˺�÷��顣\n", this_player());
        destruct(this_object());
        }
        return 1;
        }       
}

