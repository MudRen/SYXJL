#include <ansi.h>

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;

int do_fill(string arg)
{
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        if( !environment(this_player())->query("resource/water") )
                return notify_fail("����û�еط�����װˮ��\n");
        if(query_temp("decayed")) {
                message_vision("$N��"+name()+"����ı��鵹�˳���",this_player());
                message_vision("$N��"+name()+"װ����ˮ��\n",this_player());
                delete_temp("decayed");
                        }
                        
        else if( query("liquid/remaining") ){
                message_vision("$N��" + name() + "��ʣ�µ�" + query("liquid/name") + "������\n", this_player());
                message_vision("$N��" + name() + "װ����ˮ��\n", this_player());}
        else message_vision("$N��" + name() + "װ����ˮ��\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        set("liquid/type", "water");
        set("liquid/name", "��ˮ");
        set("liquid/remaining", query("max_liquid"));
        set("liquid/drink_func", 0);

        return 1;
}

