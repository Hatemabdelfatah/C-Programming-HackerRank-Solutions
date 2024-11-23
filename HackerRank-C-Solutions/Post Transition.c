#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package {
  char* id;
  int weight;
};

typedef struct package package;
struct post_office {
  int min_weight;
  int max_weight;
  package* packages;
  int packages_count;
};

typedef struct post_office post_office;

struct town {
  char* name;
  post_office* offices;
  int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
  printf("%s:\n", t.name);
  for (int i = 0; i < t.offices_count; i++) {
    printf("\t%i:\n", i);
    for (int j = 0; j < t.offices[i].packages_count; j++) {
      printf("\t\t%s\n",t.offices[i].packages[j].id );
    }
  }
}

void send_all_acceptable_packages(town* source, int source_office_index,
                                  town* target, int target_office_index) {
  int j = source->offices[source_office_index].packages_count;
  int k = target->offices[target_office_index].packages_count;
  int num_target = 0;
  package* temp = source->offices[source_office_index].packages;
  for (int i = 0; i < j; i++) {
    if ((((temp[i].weight >=
           target->offices[target_office_index].min_weight)) &&
         ((temp[i].weight <=
           target->offices[target_office_index].max_weight)))) {
      num_target++;
    }
  }
  package* replace_target = (package *)malloc(sizeof(package) * (num_target+k));
  package* replace_source = (package *)malloc(sizeof(package) * (j - num_target));
  for (int i = 0; i < k; i++)
  {
    replace_target[i] = target->offices[target_office_index].packages[i];
  }
  for (int i = 0,n = 0; i < j; i++) {
    if ((((temp[i].weight >=
           target->offices[target_office_index].min_weight)) &&
         ((temp[i].weight <=
           target->offices[target_office_index].max_weight)))) {
      replace_target[k] = source->offices[source_office_index].packages[i];
      (target->offices[target_office_index].packages_count)++;
      (source->offices[source_office_index].packages_count)--;
      k++;
    }
    else{
      replace_source[n] = source->offices[source_office_index].packages[i];
      n++;
    }
  }
  free(target->offices[target_office_index].packages);
  free(source->offices[source_office_index].packages);
  target->offices[target_office_index].packages = replace_target;
  source->offices[source_office_index].packages = replace_source;

}

town town_with_most_packages(town* towns, int towns_count) {
    int sum = 0;
    int max = 0;
    int indix = 0;
    for(int i = 0; i < towns_count; i++)
    {
        sum = 0;
        for(int j = 0; j < towns[i].offices_count; j++)
        {
            sum += towns[i].offices[j].packages_count;
        }
        if(max < sum)
        {
           max = sum;
           indix = i;
        }
    }
    return towns[indix];
}
town* find_town(town* towns, int towns_count, char* name) {
  town* temp = &towns[0];
  for (int i = 0; i < towns_count; i++) {
    if (0 == (strcmp(towns[i].name, name))) {
        temp = &towns[i];
        break;
    } else {
    }
  }
  return temp;
}

int main() {
   int towns_count;
  scanf("%d", &towns_count);
  town* towns = malloc(sizeof(town) * towns_count);
  for (int i = 0; i < towns_count; i++) {
    towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
    scanf("%s", towns[i].name);
    scanf("%d", &towns[i].offices_count);
    towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);
    for (int j = 0; j < towns[i].offices_count; j++) {
      scanf("%d%d%d", &towns[i].offices[j].packages_count,
            &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
      towns[i].offices[j].packages =
          malloc(sizeof(package) * towns[i].offices[j].packages_count);
      for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
        towns[i].offices[j].packages[k].id =
            malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].offices[j].packages[k].id);
        scanf("%d", &towns[i].offices[j].packages[k].weight);
      }
    }
  }
  int queries;
  scanf("%d", &queries);
  char town_name[MAX_STRING_LENGTH];
  while (queries--) {
    int type;
    scanf("%d", &type);
    switch (type) {
      case 1:
        scanf("%s", town_name);
        town* t = find_town(towns, towns_count, town_name);
        print_all_packages(*t);
        break;
      case 2:
        scanf("%s", town_name);
        town* source = find_town(towns, towns_count, town_name);
        int source_index;
        scanf("%d", &source_index);
        scanf("%s", town_name);
        town* target = find_town(towns, towns_count, town_name);
        int target_index;
        scanf("%d", &target_index);
        send_all_acceptable_packages(source, source_index, target,
                                     target_index);
        break;
      case 3:
        printf("Town with the most number of packages is %s\n",
               town_with_most_packages(towns, towns_count).name);
        break;
    }
  }
  return 0;
}
