// babyroom.c

#include <ansi.h>

inherit ROOM;

void create()
{
        
        seteuid(getuid());
        set("short", "¹�����׶�԰");
       set("long",
"������¹�����׶�԰������д��"HIG"����Ե�׶�԰��"NOR",��һ�����Ϳ����ö�\n"
"�ö��С���ӣ�һ������ɰ���������Baby��ʲô����û�У���\n"
"ȥ����������(���� findbaby Ѱ����ı���)\n"
        );
        set("no_fight",1);
        set("no_sleep_room",1);
        set("no_steal",1);
        set("no_beg",1);
        set("no_study",1);
        set("no_yun",1);

        set("exits", ([
                "down" : "/d/city/kedian2",
        ]));

        setup();
}
void init()
{
            add_action("do_findbaby","findbaby");
}


int do_findbaby()
{
      object me=this_player(),*list,baby,where;
      int number,size,i,j,found;
      string myid,*babyid;

      number=me->query("child");
      if(number==0) return notify_fail("����˭��  ����\n");

      myid=me->query("id");

      list=children("/u/bsd/npc/baby");
      size=sizeof(list);

      for(i=1;i<=number;i++) {
        found=0;
        if(size>0) {
          for(j=0;j<size;j++) {
            if((int)list[j]->query("baby_number")==i &&
                    list[j]->query("id")==
              me->query("child_"+i+"/id")[0]) {
              where=environment(list[j]);
              if(where) {
                found=1;
                write(list[j]->query("name")+"������");
                if(where->query("short")) {
                  write(where->query("short"));
                } else {
                  write(where->short());
                }
                write("��\n");
                break; 
// If one have more than one boys or girls, break here after first match. Dream 01/03/98.
              }
            }
          }
        }
        if(found==0) {
         if(me->query("child_"+i+"/id")) {

          //modify old baby data, for compatibility.
          if(stringp(me->query("child_"+i+"/id"))) {
            babyid=({me->query("child_"+i+"/id")})+({"baby"});
            me->set("child_"+i+"/id",babyid);
            me->save();
          }

          babyid=me->query("child_"+i+"/id");
          baby=new("/u/bsd/npc/baby");
          baby->set("per",me->query("child_"+i+"/per"));
          baby->set("long",me->query("child_"+i+"/long"));
          baby->set("gender",me->query("child_"+i+"/gender"));
          baby->set("parents",me->query("child_"+i+"/parents"));
          baby->set_name(me->query("child_"+i+"/name"),babyid);
          baby->set("baby_number",i);
          baby->move(environment(me));
          message_vision("���Ȼ����������"+
            ({"̽��һ��С�Թ�","���һ˫С��Ѿ","���һֻС��"})
            [random(3)]+"������\n",me);
         } else {
          write("Error: don't have data for baby "+i+". Please report to wiz. :)\n");
         }
        }
      }
      return 1;
}

