## Esse é o tutorial de como inserir o "gripper" no sistema MRS:

- Em cada linha, e abaixo, está os arquivos e as linhas que devem ser adicionadas em cada um deles;
- Note que os arquivos de modelos 3d na pasta "meshes", é apenas os arquivos, então serão colocados esses arquivos em uma pasta especifica;
- Lembre-se que depois de executar o processo, compilar o ambiente do sistema MRS, com o comando "catkin build" no terminal.


## spawner_params.yaml

- Coloque as linhas desse arquivo no arquivo ~/mrs_workspace/src/simulation/ros_packages/mrs_simulation/config/spawner_params.yaml


## component_snippets.xacro

- Coloque as linhas desse arquivo no arquivo ~/mrs_workspace/src/simulation/ros_packages/mrs_simulation/models/mrs_robots_description/urdf/component_snippets.xacro
- Você deve colocar na região abaixo o macro "Macro for visualization of mash with collision" (deve está próximo a linha 160)


## t650.xacro

- Coloque as linhas desse arquivo no arquivo ~/mrs_workspace/src/simulation/ros_packages/mrs_simulation/models/mrs_robots_description/urdf/t650.xacro
- Na primeira parte, procure por " holders " e adicione esta linha abaixo da ultima "xacro ::property" (deve está próximo a linha 98)
- Na segunda parte, procure por " UVDAR mount " e adicione esta linha abaixo da ultima "xacro ::property" (deve está próximo a linha 1350)


## Pasta meshes

- Coloque estes arquivos na pasta ~/mrs_workspace/src/simulation/ros_packages/mrs_simulation/models/mrs_robots_description/meshes/tarot/t650
