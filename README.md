Instruções de instalação:

  - Siga as instrunções da seção de instalação do link: https://github.com/ctu-mrs/mrs_uav_system;
  - Instale as bibliotescas: 
```
sudo apt-get update
sudo apt-get install libfftw3-dev
sudo apt-get install libclfft-dev
sudo apt-get install libcgal-dev
```
  - Na pasta home/workspace/src faça o git clone desse repositorio;
  - Siga as instruções do readme dentro da pasta "gripper";
  - Faça um catkin build no workspace;
  - Usando o terminal acesse 
```
  /home/(USER)/workspace/src/Drone_Trial_League/offshore_uav_pack/start;
```
  - Rode o comando abaixo no terminal para testar a simulação:
```
    $ ./start.sh
```
  - Apos o gazebo iniciar, vá até a aba spawn, no terminal aberto pelo comando, você pode altenar a aba usando a tecla "shift + setas", na aba spawn va para a janela de baixo usando o comando "alt + setas", nessa janela aperte a seta para cima e enter, para utilizar um comando pre-carregado, esse comando roda todos os launchs de spawns, comentados na instruções de utilização (fases), aguarde os objetos spawnarem e aperte o botão play, na parte inferior, do gazebo. Sua simulação esta iniciada.

Instruções de utilização ( Fases ):

  - As fases possuem pastas separadas dentro da pasta offshore_uav_pack, cada pasta start_fase_X possui os arquivos de iniciação do tmux e configuração do sistema MRS, para utilizar estes inicializadores, basta acessar a pasta pelo terminal, e utilizar o comando executado na instalação:
```
    $ ./start.sh
```
  - OBS: Evite alterar esses arquivos.
  - A alteração das posições dos objetos são feitas em dois arquivos:
    - O primeiro arquivo é o faseX.world, localizado na pasta
    ```
    ~/workspace/src/Drone_Trial_League/asv_wave_sim_gazebo/worlds 
    ```
      Dentro desses arquivos você encontra todos os modelos que são inseridos no mundo, junto com as suas posições
    ```
    <!-- THE LAND BASE MODEL 1 -->
      <model name="cost_base">
        <include>
          <uri>model://cost_base</uri>
          <!-- Pose ( x y z r p y ) -->
          <pose frame=''>10 90 10 1.57 0 0</pose>
        </include>
      </model>
    ```
      Como nesse exemplo, cada fase tem todos os elementos necessarios, caso deseje adicionar um elemento, lembre-se que os "model name" devem ser unicos.

    - O segundo arquivo é o spawn_obj_wamvX.launch, localizado na pasta
    ```
    ~/workspace/src/Drone_Trial_League/offshore_uav_pack/launch
    ```
      Dentro desses arquivos você encontra a posição especifica de um determinado objeto e onde ele deve ser spawnado, abaixo segue a referencia dos arquivos:
      - spawn_equip_wamv1.launch - Spawna a caixa com qrcode, no wamv 1
      - spawn_equip_wamv2.launch - Spawna a caixa com qrcode, no wamv 2
      - spawn_equip_wamv3.launch - Spawna a caixa com qrcode, no wamv 3
      - spawn_mes_wamv.launch - Spawna o medidor, no wamv 1
      - spawn_wamv1.launch - Spawna o wamv 1
      - spawn_wamv2.launch - Spawna o wamv 2
      - spawn_wamv3.launch - Spawna o wamv 3
      Os arquivos são descritos da seguinte forma:
    ```
        <arg name="robot_name" value="equipmentA"/>
        <arg name="x" value="14.8" />
        <arg name="y" value="-15.0" />
        <arg name="z" value="1.6" />
        <arg name="roll" value="0"/>
        <arg name="pitch" value="0"/>
        <arg name="yaw" value="0.0" />
        <arg name="sdf_robot_file" value="$(find asv_wave_sim_gazebo)/models/equipmentA/model.sdf" />
    ```
      Apenas é necessario mudar os argumentos x, y, z, roll, pitch, yaw, para alterar a posição, porem caso deseje alterar o QRcode, mude a letra nas palavras "equipmentA" para a letra referente ao qual você deseja, exemplo para alterar a letra do QRcode para B: 
    ```
        <arg name="robot_name" value="equipmentB"/>
        <arg name="x" value="14.8" />
        <arg name="y" value="-15.0" />
        <arg name="z" value="1.6" />
        <arg name="roll" value="0"/>
        <arg name="pitch" value="0"/>
        <arg name="yaw" value="0.0" />
        <arg name="sdf_robot_file" value="$(find asv_wave_sim_gazebo)/models/equipmentB/model.sdf" />
    ```
      Lembre-se que as caixas devem esta em cima dos barcos, logo se alterar a posição dos barcos lembre-se de ajustar a posição das caixas.

Instruções de utilização ( Controlador da garra ):

  - O controlador da garra é iniciado pelo comando
    ```
    roslaunch controller_g ControllerG.launch
    ```
    O mesmo apenas inicia o serviço do controlador, as suas ações são comandadas pelo serviço
    ```
    rosservice call /uav1/control_manager/controller_gripper "stance: ''"
    ```
    Onde em stance, deve-se colocar um dos argumentos:
    - "open" - Executa a abertura da garra;
    - "close" - Executa o fechamento da garra;
    - "up" - Executa o reposicionamento da garra para a posição aonde esta acima do trem de pouso;
    - "Down" - Executa o reposicionamento da garra para a posição aonde esta abaixo do trem de pouso;

Instruções gerais:
  - Para demais detalhes sobre os arquivos, é recomendado assistir o video descritivo do pacote da competição do ano passado, que esta no link: https://youtu.be/aM0vAr_YDT8
  - Para alterar a posição de spawn do drone acesse o arquivo uav1_pos.yaml na pasta start

