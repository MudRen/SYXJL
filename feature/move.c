// move.c
// modify By Slap@ldj 5/2000

#include <dbase.h>
#include <ansi.h>
#include <room.h>

#define TIME_CHECK NATURE_D->outdoor_room_description()
nosave int weight = 0;
nosave int encumb = 0, max_encumb = 0;

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }

nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }
nomask void add_encumbrance(int w)
{
        encumb += w;
        if( encumb < 0 )
                log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
        if( encumb > max_encumb ) this_object()->over_encumbrance();
        if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
        if( !interactive(this_object()) ) return;
        tell_object(this_object(), "��ĸ��ɹ����ˣ�\n");
}

nomask int query_weight() { return weight; }
nomask void set_weight(int w)
{
        if( !environment() ) {
                weight = w;
                return;
        }
        if( w!=weight ) environment()->add_encumbrance( w - weight );
        weight = w;
}


// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight() { return weight + encumb; }

varargs int move(mixed dest, int silently)
{
        object ob, env, *inv;
        string str, *dirs;
        int i, j, k, l, night_check, char_p, obj_p;
        mapping exits, *data;

        k = 0;
        data = allocate(3000);

        // If we are equipped, unequip first.
        if( query("equipped") && !this_object()->unequip() )
                return notify_fail("��û�а취ȡ������������\n");

        // Find the destination ob for moving.
        if( objectp(dest) )
                ob = dest;
        else if( stringp(dest) ) {
                call_other(dest, "???");
                ob = find_object(dest);
                if(!ob) return notify_fail("move: destination unavailable.\n");
        } else
                return notify_fail(sprintf("move: invalid destination %O.\n", dest));

        // Check if the destination ob can hold this object.
        // Beforce checking it, we check if the destination is environment of
        // this_object() (or environment of its environment). If it is, then
        // this could be like get something from a bag carried by the player.
        // Since the player can carry the bag, we assume he can carry the this
        // object in the bag and encumbrance checking is unessessary.
        env = this_object();
        while(env = environment(env)) if( env==ob ) break;
        if( !env && (int)ob->query_encumbrance() + weight()
                > (int)ob->query_max_encumbrance() ) {
                if( ob==this_object() )
                        return notify_fail( this_object()->name() + "�������̫���ˡ�\n");
                else
                        return notify_fail( this_object()->name() + "��" + ob->name() + "����̫���ˡ�\n");
        }

        // Move the object and update encumbrance
        if( environment() ) environment()->add_encumbrance( - weight());
        move_object(ob);
        ob->add_encumbrance(weight());

        // If we are players, try look where we are.
        if( interactive(this_object())          // are we linkdead?
        &&      living(this_object())                   // are we still concious?
        &&      !silently
        &&      userp(this_object())) {
                if( query("env/brief") )
                {
// modify by slap@ldj
                        env = environment();
                        if( (strsrch(TIME_CHECK, "ҹ��") != -1 || strsrch(TIME_CHECK, "��ҹ") != -1)
                                && env->query("outdoors") != 0
                                && (!this_object()->query_temp("night/light") || !present(this_object(), env))
                                && !wizardp(this_object()) )
                        night_check = 1;
                        else night_check = 0;

                        str = sprintf( "\n"HIC"%s"NOR"%s%s%s",
                                env->query("short"),
                                wizardp(this_object())? file_name(env): "",
                                ( night_check == 1 && env->query("outdoors") )?
                                HIB"\n    ҹ���ˣ�����Ȼ�������۾���ϸ�ۿ����ɻ��ǿ��������Χ\n" +
                                "�����һ�ж���ҹɫ�����֣������µĵ�·��ģ��������... \n" NOR:"\n",
                                env->query("outdoors")? NATURE_D->outdoor_room_description():""
                        );

                        if( !mapp(env->query("exits")) )
                                str += WHT"    ����û���κ����Եĳ�·��\n"NOR;
                        if( mapp(exits = env->query("exits")) ) {
                                dirs = keys(exits);
                                for(i=0; i<sizeof(dirs); i++)
                                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                                dirs[i] = 0;
                                dirs -= ({ 0 });
                                if( sizeof(dirs)==0 )
                                        str += WHT"    ����û���κ����Եĳ�·��\n"NOR;

                                else if( night_check && random(this_object()->query_con()) < 35 ) {
                                        i = random(sizeof(dirs));
                                        if( random(this_object()->query_con()) < 10 ) i = 0;
                                        else if( random(this_object()->query_con()) < 20 ) i = 1;
                                        if( i <= 0 )
                                                str += WHT"    ���￴�����κ����Եĳ�·��\n"NOR;
                                        else if( i == 1 )
                                                str += WHT"    ���￴�ü���Ψһ������ "WHT + dirs[i-1] + NOR"��\n"NOR;
                                        else str += sprintf(WHT"    ���￴����ĳ����� "WHT + "%s" + NOR"��\n"NOR, implode(dirs[1..i], "��"));
                                }

                                else if( sizeof(dirs)==1 )
                                        str += "    ����Ψһ�ĳ����� "HIG + dirs[0] + NOR "��\n";
                                else
                                        str += sprintf("    �������Եĳ����� "HIG"%s"NOR" �� "HIG"%s"NOR"��\n",
                                                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
                        }

                        inv = all_inventory(environment());
                        if( night_check ) {
                                for (i = 0; i < sizeof(inv); i++) {
                                        if (inv[i]!=this_object() && this_object()->visible(inv[i]) && living(inv[i])) {
                                                char_p = 1;
                                                if (inv[i]->query_temp("night/light")) {
                                                        str += "  " + inv[i]->short() + "������һ��"HIR +
                                                                inv[i]->query_temp("night/light") + NOR"����������\n";
                                                }
                                        }
                                        else if (!living(inv[i]) || !inv[i]->is_character())
                                                obj_p = 1;
                                }
                                if (char_p)
                                        str += "  һЩģ����Ӱ�ӣ���Ȼ���������\n";
                                if (obj_p)
                                        str += "  һ��ģ���Ķ�������Ȼ���������\n";
                                tell_object(this_object(), str);
                        } else {
                                for (i = 0; i < sizeof(inv); i++) {
                                        if (inv[i]!=this_object()
                                        &&  this_object()->visible(inv[i])
                                        &&  !inv[i]->query("money_id")
                                        &&  !inv[i]->query_temp("check_only"))
                                        {
                                                data[k]=([]);
                                                for(j = i; j < sizeof(inv); j++ )
                                                {
                                                        if ( inv[i]->query("name")==inv[j]->query("name")
                                                        &&   inv[i]->query("id")==inv[j]->query("id")
                                                        &&   !inv[j]->query_temp("check_only") )
                                                        {
                                                                data[k]["id"]=inv[i]->short();
                                                                data[k]["unit"]=inv[i]->query("unit");
                                                                data[k]["num"]= data[k]["num"] + 1;
                                                                inv[j]->set_temp("check_only", 1);
                                                        }
                                                        else continue;
                                                }
                                                k++;
                                        }
                                        else continue;
                                }

                                for (i = 0; i < sizeof(inv); i++) {
                                        if ( !inv[i]->query_temp("check_only") && inv[i]!=this_object()
                                                && this_object()->visible(inv[i]) )
                                        str += sprintf("%s%s\n", "  ", inv[i]->short());
                                }
                                for (i = 0; i < sizeof(inv); i++)
                                        if ( inv[i]->query_temp("check_only") )
                                                inv[i]->delete_temp("check_only");

                                if (k > 0)
                                {
                                        for (l = 0; l < k; l++)
                                                str = sprintf("%s%s%s\n", str,  (data[l]["num"]==1)? "  ":"  "
                                                        + chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"]);
                                }
// end
                                tell_object(this_object(), str);
                        }
                }
                else
                        command("look");
        }
        return 1;
}

void remove(string euid)
{
        object default_ob;

        if( userp(this_object()) && euid!=ROOT_UID ) {
                log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
                        euid, this_object()->query("id"), ctime(time())));
                error("��(" + euid + ")���ܴݻ�������ʹ���ߡ�\n");
        } else if( this_object()->query("equipped")) {
                if(     !this_object()->unequip() )
                        log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
        }

        // We only care about our own weight here, since remove() is called once
        // on each destruct(), so our inventory (encumbrance) will be counted as
        // well.
        if( environment() )     environment()->add_encumbrance( - weight );
        if( default_ob = this_object()->query_default_object() )
                default_ob->add("no_clean_up", -1);
}

int move_or_destruct( object dest )
{
        if( userp(this_object()) ) {
                tell_object(this_object(), "һ��ʱ�յ�Ť�����㴫�͵���һ���ط�....\n");
                move(VOID_OB);
        }
}

