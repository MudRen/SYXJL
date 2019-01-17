inherit ROOM;

void create()
{
        set("short", "��ħ��");
        set("long", @LONG
����Ƕ������ܵ����ӱ�������׷ɱ�ĵط���ï�ܵĲ�ľ
ʹ��������Ū�������һ������������Ժ��лص���
        �����ȥ�ˣ��������������...........!!!!��
LONG
        );
        set("outdoors", "oldpine");
        
        setup();
}

void reset()
{
        ::reset();
        set("exits", ([ /* sizeof() == 5 */
          "south" : __DIR__"climb" + (random(10)+1),
          "north" : __DIR__"climb" + (random(10)+1),
          "west" : __DIR__"climb" + (random(10)+1),
          "east" : __DIR__"climb" + (random(10)+1),
        ]));
}

int valid_leave(object me, string dir)
{
        if ( dir == "west")
            me->add_temp("mark/steps",1);
        if ( dir == "east")
            me->add_temp("mark/steps",-1);

        if ( dir == "south")
            me->add_temp("mark/steps",1);
        if ( dir == "north")
            me->add_temp("mark/steps",-1);

        if (me->query_temp("mark/steps") == 10)
         {
            me->move(__DIR__"climb4");
            me->delete_temp("mark/steps");
             return notify_fail("���۵ð���������߳�������\n");
         }  

     if (me->query_temp("mark/steps") == -10)
            {  
               me->move(__DIR__"climb4");
           me->delete_temp("mark/steps");
             return notify_fail("���۵ð���������߳�������\n");
        }

        return ::valid_leave(me,dir);
}

