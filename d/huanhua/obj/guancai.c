// crate.c

inherit ITEM;

void create()
{
        set_name("�ײ�", ({ "guancai", "guan"}));
        set_weight(40000);
        if( !clonep() ) {
                set("unit", "��");
                set("long", "����һ��������Ĵ�ײġ���֪��װ�����ĸ����ӵ�ʬ�塣��\n");
                set("value", 1);
                set("wage", 5);
        }
        setup();
}

void init()
{
        add_action("do_get", "get");
}

int do_get(string arg)
{
        if( environment() != environment(this_player())
        ||      !id(arg) ) return 0;

        if( (int)this_player()->query_stat("qi") < 10 ) {
                write("������������ˣ���Ϣһ����˵�ɡ�\n");
                return 1;
        }

        if( move(this_player()) ) {
                message_vision("$N�����������ϵ�" + name() + "����������\n", this_player());
                this_player()->consume_stat("qi", 10);
                return 1;
        }
}

