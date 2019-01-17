mapping valid_login = ([
       "zzt":          ({ "202.103.48","202.103.47.","10.57." }),
       "yanzi":          ({ "202.103.48","202.103.47.","10.57." }),
       "cloud":          ({ "202.103.108" }),
//        "snow":         ({ "155.69.", "%*s.ntu.edu.sg" }),

]);

int is_valid(string id, string ip)
{
        int i;

        if (ip == "127.0.0.1" || ip == "localhost")
                if (wiz_level(id)) return 1;
                else if(id == "zen") return 1;
                else return 0;
        if (undefinedp(valid_login[id])) return 1;
        i = sizeof(valid_login[id]);
        while (i--) if (sscanf(ip, valid_login[id][i] + "%*s")) return 1;
        return 0;
}

mapping valid_multi = ([
        "127.0.0.1":            0,
        "192.168.1.":           6,
        "":                     0
]);

int is_multi(string id, string ip)
{
        object *usr = filter_array(users(), (: interactive :));
        string *site = keys(valid_multi);
        int i = sizeof(usr), login_cnt = 0;

        while (i--) if (usr[i]->query("id") != id && query_ip_number(usr[i]) == ip) login_cnt++;
        if (!login_cnt) return 0;
        i = sizeof(valid_multi);
        while (i--) if (sscanf(ip, site[i] + "%*s")) break;
        if (i < 0) {
        write("�Բ�����Ŀǰ�ĵ�ַ��ֹ���ص�¼��������ʦ��ϵ��\n");
                return 1;
        }
        if (!(i = valid_multi[site[i]])) return 0;
        if (login_cnt < i) return 0;
        write("�Բ�����Ŀǰ�ĵ�ַ�ѵ����������ƣ�������ʦ��ϵ��\n");
        return 1;
}

