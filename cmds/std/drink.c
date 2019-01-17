#include <ansi.h>

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;

int do_drink(string arg)
{
        object obj,me;
        me=this_player();
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        if(!objectp(obj = present(arg, me)) ){
                     if(objectp(obj = present(arg, environment(me))) && !obj->is_character() )
                   tell_room(environment(me), me->name() + "���Ÿɿݵ��촽�������ض��ŵ��ϵ�"+obj->name() + "��\n",({ me }));
                return notify_fail("������û������������\n");           
                }
        if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? "�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n":"�ǿյġ�\n"));
        if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
                return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");
        if(obj->query_temp("decayed")) return notify_fail("ˮ����ɱ��ˣ���ô��ѽ!\n");
        add("liquid/remaining", -1);
        message_vision("$N����" + name() + "������غ��˼���" + query("liquid/name")
                + "��\n", this_player());
        this_player()->add("water", 30);
        if( this_player()->is_fighting() ) this_player()->start_busy(2);
        if( !query("liquid/remaining") )
                write("���Ѿ���" + name() + "���" + query("liquid/name")
                        + "�ȵ�һ��Ҳ��ʣ�ˡ�\n");

        // This allows customization of drinking effect.
        if( query("liquid/drink_func") ) return 1;

        switch(query("liquid/type")) {
                case "alcohol":
                        this_player()->apply_condition("drunk",
                                (int)this_player()->query_condition("drunk") 
                                + (int)query("liquid/drunk_apply"));
                        break;
        }
        
        return 1;
}

