// crate.c

inherit ITEM;

void create()
{
        set_name("棺材", ({ "guancai", "guan"}));
        set_weight(40000);
        if( !clonep() ) {
                set("unit", "个");
                set("long", "这是一个黑漆漆的大棺材。不知道装的是哪个弟子的尸体。　\n");
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
                write("你的力气不够了，休息一下再说吧　\n");
                return 1;
        }

        if( move(this_player()) ) {
                message_vision("$N弯下腰将地上的" + name() + "扛了起来　\n", this_player());
                this_player()->consume_stat("qi", 10);
                return 1;
        }
}

