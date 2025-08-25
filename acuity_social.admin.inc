<?php
/**
 * @file
 * Admin page callbacks and forms for the Acuity Social module.
 */

/**
 * Form constructor for the social channel entity (add and edit).
 */
function acuity_social_channel_form($form, &$form_state, $acuity_social_channel) {
  // Store the entity object in the form state for other functions to use.
  $form_state['acuity_social_channel'] = $acuity_social_channel;

  // The title is a base property of our entity.
  $form['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $acuity_social_channel->title,
    '#required' => TRUE,
    '#weight' => -10,
  ];

  // This powerful function automatically adds form elements for any fields
  // you attach to the entity, like a body field or image field.
  field_attach_form('acuity_social_channel', $acuity_social_channel, $form, $form_state);

  $form['actions'] = ['#type' => 'actions'];
  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => $acuity_social_channel->is_new() ? t('Create Channel') : t('Save Channel'),
  ];

  return $form;
}

/**
 * Form submission handler for acuity_social_channel_form().
 */
function acuity_social_channel_form_submit($form, &$form_state) {
  $acuity_social_channel = $form_state['acuity_social_channel'];

  // For new channels, set the author to the current user.
  if ($acuity_social_channel->is_new()) {
    $acuity_social_channel->uid = $GLOBALS['user']->uid;
  }

  // The entity object is automatically updated with form values by Backdrop.
  // We just need to save it.
  $acuity_social_channel->save();

  backdrop_set_message(t('Social channel @title has been saved.', ['@title' => $acuity_social_channel->label()]));
  $form_state['redirect'] = 'social-channel/' . $acuity_social_channel->id();
}

/**
 * Form constructor for the channel delete confirmation form.
 */
function acuity_social_channel_delete_form($form, &$form_state, $acuity_social_channel) {
  $form_state['acuity_social_channel'] = $acuity_social_channel;

  // Use Backdrop's standard confirmation form function.
  return confirm_form(
    $form,
    t('Are you sure you want to delete the channel %title?', ['%title' => $acuity_social_channel->label()]),
    'social-channel/' . $acuity_social_channel->id(), // Path to return to if the user cancels.
    t('This action cannot be undone.'),
    t('Delete') // Text for the confirmation button.
  );
}

/**
 * Form submission handler for acuity_social_channel_delete_form().
 */
function acuity_social_channel_delete_form_submit($form, &$form_state) {
  $acuity_social_channel = $form_state['acuity_social_channel'];
  $acuity_social_channel->delete();

  backdrop_set_message(t('The social channel %title has been deleted.', ['%title' => $acuity_social_channel->label()]));
  $form_state['redirect'] = '<front>'; // Redirect to the front page after deletion.
}